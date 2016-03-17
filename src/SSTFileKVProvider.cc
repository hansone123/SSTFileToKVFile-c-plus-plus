/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <leveldb/env.h>

#include "SSTFileKVProvider.h"

SSTFileKVProvider::SSTFileKVProvider(){
	env_ = leveldb::Env::Default();
}

SSTFileKVProvider::~SSTFileKVProvider(){
	close();
}

long SSTFileKVProvider::countFileSizeByte(const string FilePath) const{
	FILE *openFile;
	long FileSize;
	if(!(openFile = fopen(FilePath.c_str(), "r"))){
		return false;
	}
	fseek(openFile, 0, SEEK_END);
	FileSize = ftell(openFile);
	fclose(openFile);
	return FileSize;
}

bool SSTFileKVProvider::init(const string FilePath){

	leveldb::Status status;
	leveldb::Options options;

	//close();
	env_ = leveldb::Env::Default();
	long sstFileSize = countFileSizeByte(FilePath);
	status = env_->NewRandomAccessFile(FilePath, &sstFile_);
	if(!status.ok()) return status.ok();

	status = leveldb::Table::Open(options, sstFile_,
			sstFileSize, &sstTable_);
	if(!status.ok()) return status.ok();

	iter_ = sstTable_->NewIterator(leveldb::ReadOptions());
	iter_->SeekToFirst();
	//	for (iter_->SeekToFirst(); iter_->Valid(); iter_->Next()) {
	//		cout << iter_->key().ToString() << ": " <<
	//				iter_->value().ToString() << endl;
	//	}
	//	if (iter_ == NULL)
	//		printf("error finish\n");
	return status.ok();
}

void SSTFileKVProvider::close(){
	delete iter_;
	delete sstTable_;
	delete sstFile_;
}

char* SSTFileKVProvider::getKey(int& keySize) const{
	keySize = iter_->key().size() - 8;
	return(char*)this->iter_->key().data();
}

char* SSTFileKVProvider::getValue(int& valueSize) const{
	valueSize = iter_->value().size();
	return(char*)this->iter_->value().data();
}

bool SSTFileKVProvider::next(){
	iter_->Next();
	return iter_->Valid();
}
