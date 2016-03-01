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

using namespace std;

class FileObserver {
private:
    string directoryPath;
public:
    void setDirectory(string path);
    bool setValidDirectoryPath(string dirName);
    string chooseFile();
    void doJob(string fileName);
    bool dirIsEmpty();
    bool keepWatchOnDirectoryAndDoJob();
    FileObserver();
    FileObserver(const FileObserver& orig);
    virtual ~FileObserver();
private:
    bool dirIsExisted(string dirName);
};

#endif /* FILEOBSERVER_H */

