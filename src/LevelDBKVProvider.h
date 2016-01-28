/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelDBKVProvider.h
 * Author: hanson
 *
 * Created on January 27, 2016, 5:59 PM
 */

#ifndef LEVELDBKVPROVIDER_H
#define LEVELDBKVPROVIDER_H

#include <string>
#include "KVProvider.h"
#include "../include/leveldb/db.h"

using namespace std;

class LevelDBKVProvider : public KVProvider{
public:
    bool init(string path);
    char* getKey(int &k);
    char* getValue(int &v);
    bool next();
    ~LevelDBKVProvider();
private:
    leveldb::DB* db;
    leveldb::Iterator* it;
    
};


#endif /* LEVELDBKVPROVIDER_H */

