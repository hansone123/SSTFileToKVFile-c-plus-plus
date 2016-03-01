/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileObserver.cc
 * Author: hansone123
 * 
 * Created on March 1, 2016, 3:54 AM
 */

#include <string>
#include <sys/stat.h>
#include "FileObserver.h"
#include <iostream>

void FileObserver::setDirectory(string directoryPath) {
    this->directoryPath = directoryPath;
}
bool FileObserver::setValidDirectoryPath(string directoryPath) {
    
    this->setDirectory(directoryPath);
    if (!this->dirIsExisted(directoryPath)){
        return false;
    }
    cout<<"set directory to :"<<directoryPath;
    return true;
}
bool FileObserver::dirIsExisted(string directoryPath) {
    
    struct stat sb;
    if (stat(directoryPath.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode)) {
        return true;
    }
    return false;
}
string FileObserver::chooseFile() {
    string fileName = "";
    return this->directoryPath + fileName;
}

void FileObserver::doJob(string fileName) {
    
}

bool FileObserver::keepWatchOnDirectoryAndDoJob() {
    while(true) {
        string filename = this->chooseFile();
        this->doJob(filename);
        break;
    }
}
bool FileObserver::dirIsEmpty() {
    
}
FileObserver::FileObserver() {
}

FileObserver::FileObserver(const FileObserver& orig) {
}

FileObserver::~FileObserver() {
}

