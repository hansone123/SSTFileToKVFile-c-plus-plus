/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kvFile.cc
 * Author: hansone123
 * 
 * Created on January 31, 2016, 6:46 PM
 */

#include "kvFile.h"
#include "KVProvider.h"
#include "Varint64.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

using namespace std;

char *kvFile::addHeader(int& o_sz, char* i_s, int i_sz) {
    char hdr_buf[9];
    int hdr_sz;
    
    hdr_sz = Varint::uint64ToVarint((uchar*)hdr_buf, i_sz);
    
    int o_size = i_sz+hdr_sz;
    char *o_s = new char[o_size];
    strncpy(o_s, hdr_buf, hdr_sz);                   //copy hdr
    strncpy(o_s + hdr_sz, i_s, i_sz);                //copy string
    o_sz = o_size;
    
    return  o_s;
}

bool kvFile::openFile(string name) {
    this->file.open(name.c_str(), ios::out | ios::trunc);
    if (!this->file)
        return false;
    return true;
}

void kvFile::writeToFile(char *i_s, int i_sz) {
    int o_sz;
    char* o_s = this->addHeader(o_sz, i_s , i_sz);    //add varint about string-size 
    this->file.write(o_s, o_sz);
}
void kvFile::close() {
    if (this->file) {
        this->file.close();
    }        
}
kvFile::kvFile() {
    
}

kvFile::kvFile(const kvFile& orig) {
}

kvFile::~kvFile() {
}

