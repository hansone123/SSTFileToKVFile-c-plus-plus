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

string FileObserver::getDirectoryPath() {
    return this->directoryPath;
}
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
    
    string resultFileName ="";
    
    vector<string> files = this->getAllFileNamesInDirectory();
    if (files.size() == 0) {
        cout<<"directory is empty ."<<endl;
        return resultFileName;
    }
    
    resultFileName = files.front();
    
    for(int i=0; i<files.size(); i++) {;
        if (strcmp(resultFileName.c_str(), files[i].c_str()) >0) {
            resultFileName = files[i];
        }
    }
    resultFileName = this->getDirectoryPath() + "//" + resultFileName;
    
    return resultFileName;
}
vector<string> FileObserver::getAllFileNamesInDirectory() {
    
    vector<string> result;
    string direcoryPath = this->getDirectoryPath();
    DIR *directory = opendir(direcoryPath.c_str());
    if (!directory) {
        return result;
    }
    
    struct dirent *dirp;
    while ((dirp = readdir(directory)) != NULL) {
        string temp = string(dirp->d_name);
        if ((temp.compare(".") > 0) && (temp.compare("..") > 0) ) {
            result.push_back(temp);
        }
    }
    closedir(directory);
    
    return result;
    
}
void FileObserver::doJob(string fileName) {
    
    kvToCSV kvt;
    kvt.setInputFilePath(fileName);
    kvt.setOutputDirectory("/tmp/KVoutput");
    
    if (kvt.outputCSV() != 0 ) {
        cout<<"output "<<fileName<<" failed."<<endl;
    }
    
}

void FileObserver::keepWatchOnDirectoryAndDoJob() {
    while(true) {
        string fileName = this->chooseFile();
        
        if (fileName != "") {
            this->doJob(fileName);
            this->deleteFile(fileName);
        }            
    }
}
bool FileObserver::deleteFile(string fileName) {
    
    
    int flag = remove(fileName.c_str());
    
    cout<<"Delete "<<fileName<<" :"<<flag<<"  ."<<endl;
    return true;
}

FileObserver::FileObserver() {
}

FileObserver::FileObserver(const FileObserver& orig) {
}

FileObserver::~FileObserver() {
}

