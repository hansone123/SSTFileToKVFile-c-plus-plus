/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SSTFileKVProvider.h
 * Author: hank
 *
 * Created on March 10, 2016, 6:25 AM
 */

#ifndef SSTFILEKVPROVIDER_H
#define SSTFILEKVPROVIDER_H

#include "KVProvider.h"
#include "leveldb/db.h"
#include "leveldb/iterator.h"
#include "leveldb/table.h"

class SSTFileKVProvider: public KVProvider {
public:
	SSTFileKVProvider();
	virtual bool init(const string FilePath);
	virtual void close();
	virtual char* getKey(int &keySize) const;
	virtual char* getValue(int &valueSize) const;
	virtual bool next();
	~SSTFileKVProvider();
private:
	leveldb::Iterator *iter_;
	leveldb::Table *sstTable_;
	leveldb::Env *env_;
	leveldb::RandomAccessFile *sstFile_;

	long countFileSizeByte(const string FilePath) const;
};


#endif /* SSTFILEKVPROVIDER_H */

