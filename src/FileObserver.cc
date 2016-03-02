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

#include <string.h>
#include <sys/stat.h>
#include "FileObserver.h"
#include "KVToCSV.h"
#include <iostream>
#include <vector>
#include <dirent.h>
#include <stdio.h>
using namespace std;

void FileObserver::setDirectory(string directoryPath) {
    this->directoryPath = directoryPath;
}
bool FileObserver::setValidDirectoryPath(string directoryPath) {
    
    this->setDirectory(directoryPath);
    if (!this->dirIsExisted(directoryPath)){
        return false;
    }
    cout<<"set directory to :"<<directoryPath<<endl;
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
    
    if (this->dirIsEmpty())
        return NULL;
    
    DIR *directory = opendir(this->directoryPath.c_str());
    vector<string> files = vector<string>();
    struct dirent *dirp;
    while ((dirp = readdir(directory)) != NULL) {
        string temp = string(dirp->d_name);
        if ((temp.compare(".") > 0) && (temp.compare("..") > 0) ) {
            files.push_back(temp);
        }
    }
    closedir(directory);
    
    string resultFileName = files[0];
    for(int i=0; i<files.size(); i++) {
        cout<<files[i]<<endl;
        if (strcmp(resultFileName.c_str(), files[i].c_str()) >0) {
            resultFileName = files[i];
        }
    }
    resultFileName = this->directoryPath + "//" + resultFileName;
    cout<<"choose file :"<<resultFileName<<" ."<<endl;
    
    return resultFileName;
}

void FileObserver::doJob(string fileName) {
    
    kvToCSV kvt;
    kvt.setInputFilePath("testdb");
    kvt.setOutputFolder("/tmp/KVoutput");
    
    if (kvt.outputCSV() != 0 ) {
        cout<<"output "<<fileName<<" failed.";
    }else {
        cout<<"output "<<fileName<<" to KVfile."<<endl;
    }
    
}

void FileObserver::keepWatchOnDirectoryAndDoJob() {
    while(true) {
        string fileName = this->chooseFile();
        if (fileName ==NULL) {
            continue;
        }
            
        this->doJob(fileName);
        this->deleteFile(fileName);
        break;
    }
}
bool FileObserver::deleteFile(string fileName) {
    
    
    int flag = remove(fileName.c_str());
    
    cout<<"Delete "<<fileName<<" :"<<flag<<"  ."<<endl;
    return true;
}
bool FileObserver::dirIsEmpty() {
    DIR *dirPointer;
    if ((dirPointer = opendir(this->directoryPath.c_str()))) {
        return false;
    }
    closedir(dirPointer);
    
    return true;
}
FileObserver::FileObserver() {
}

FileObserver::FileObserver(const FileObserver& orig) {
}

FileObserver::~FileObserver() {
}

