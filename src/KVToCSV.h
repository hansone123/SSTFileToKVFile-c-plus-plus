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
    string outputDirectoryPath;
    string inputFilePath;
public:
    kvToCSV();
    bool init();
    void setInputFilePath(string path); 
    void setOutputDirectory(string path);
    int outputCSV();    
    
private:
    string getOSTime();
    string genCSVFileName();
    string chooseInputFile();  
    void createOuputDirectory(string p);
    bool isFileExisted(string fileName);
    
};

#endif /* KVTOCSV_H */

