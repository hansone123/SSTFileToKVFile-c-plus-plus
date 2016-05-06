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

void kvFile::writeOutHeader(int size) {
    char header[9];
    int header_size;
    
    header_size = Varint::uint64ToVarint((uchar*)header, size);
    this->file.write(header, header_size);
}
void kvFile::writeOutData(char data[], int data_size) {
       
    this->file.write(data, data_size);
}
bool kvFile::openFile(string name) {
    this->file.open(name.c_str(), ios::out | ios::trunc);
    if (!this->file)
        return false;
    return true;
}

void kvFile::addHeaderAndWriteToFile(char *data, int data_size) {
    
    this->writeOutHeader(data_size);    //add varint about string-size 
    this->writeOutData(data, data_size);
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

