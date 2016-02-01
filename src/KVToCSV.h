/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kvToCSV.h
 * Author: hanson
 *
 * Created on January 27, 2016, 11:11 PM
 */

#ifndef KVTOCSV_H
#define KVTOCSV_H

#include <string>
using namespace std;

class kvToCSV{
private:
    int num;
    string nowTime;
    string outPath;
    string inPath;
public:
    kvToCSV();
    bool init();    
    int outputCSV();    
    
private:
    string getTime();
    string genCSVFileName();
    string getInputFile();  
    void setInputPath(string path);
    void setOutputFolder(string path);
    void createOuputFolder(string p);
    
};

#endif /* KVTOCSV_H */

