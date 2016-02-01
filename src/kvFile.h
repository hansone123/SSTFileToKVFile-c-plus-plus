/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kvFile.h
 * Author: hansone123
 *
 * Created on January 31, 2016, 6:46 PM
 */

#ifndef KVFILE_H
#define KVFILE_H


#include <fstream>
#include <string>

using namespace std;

class kvFile {
    
private:
    fstream file;
    
public:
    
    bool openFile(string name);
    void writeToFile(char *i_s, int i_sz);
    void close();
    kvFile();
    kvFile(const kvFile& orig);
    virtual ~kvFile();
private:
    char *addHeader(int &o_sz, char* i_s, int i_sz);
};

#endif /* KVFILE_H */

