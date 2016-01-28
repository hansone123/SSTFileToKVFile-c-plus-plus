/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "LevelDBKVProvider.h"
#include <iostream>

using namespace std;

bool LevelDBKVProvider::init(string path) {
    leveldb::Options options;
    options.create_if_missing = false;
    leveldb::Status status = leveldb::DB::Open(options, path, &this->db);
    
    if (!status.ok()) {
        cout<<"Initial LevelDBKVProvider failed."<<endl;
        return false;
    }
        
    
    this->it = this->db->NewIterator(leveldb::ReadOptions());
    this->it->SeekToFirst();
    
    if (!this->it->Valid()) {
        cout<<"Initial LevelDBKVProvider failed."<<endl;
        return false;
    }        
    
    return true;
}

bool LevelDBKVProvider::next() {
    this->it->Next();
    if (!this->it->Valid())
        return false;
    return true;
}

char* LevelDBKVProvider::getKey(int &k) {
    k = this->it->key().size();
    return (char*)this->it->key().data();
}

char* LevelDBKVProvider::getValue(int &v) {
    v = this->it->value().size();
    return (char*)this->it->value().data();
}

LevelDBKVProvider::~LevelDBKVProvider(){
    delete this->db;
}