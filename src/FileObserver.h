/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileObserver.h
 * Author: hansone123
 *
 * Created on March 1, 2016, 3:54 AM
 */

#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include <string>
#include <vector>

using namespace std;

class FileObserver {
private:
    string directoryPath;
public:
    
    bool setValidDirectoryPath(string dirName);
    
    string chooseFile();
    void doJob(string fileName);
    bool deleteFile(string fileName);
    vector<string> getAllFileNamesInDirectory();
    void keepWatchOnDirectoryAndDoJob();
    FileObserver();
    FileObserver(const FileObserver& orig);
    virtual ~FileObserver();
private:
    void setDirectory(string path);
    string getDirectoryPath();
    bool dirIsExisted(string dirName);
};

#endif /* FILEOBSERVER_H */

