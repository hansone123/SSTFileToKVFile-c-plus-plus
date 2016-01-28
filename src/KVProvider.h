/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KVProvider.h
 * Author: hanson
 *
 * Created on January 27, 2016, 5:40 PM
 */

#ifndef KVPROVIDER_H
#define KVPROVIDER_H

#include <string>

using namespace std;

class KVProvider{
public:
    virtual bool init(string path)=0;
    virtual char* getKey(int &k)=0;
    virtual char* getValue(int &v)=0;
    virtual bool next()=0;
    static KVProvider *KVPfactory();
    static void Kill(KVProvider *kvp);
private:
};


#endif /* KVPROVIDER_H */

