/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "KVToCSV.h"
#include <string>
#include "KVProvider.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include "kvFile.h"
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

void show(char *z, int n);

kvToCSV::kvToCSV() {
    this->num = 1;
}
void kvToCSV::setInputFilePath(string p) {
    this->inputFilePath = p;
}
void kvToCSV::setOutputDirectory(string p) {
    this->createOuputDirectory(p);
    this->outputDirectoryPath = p;
}
void kvToCSV::createOuputDirectory(string dirName) {
    DIR *dir = opendir(dirName.c_str());
    if ( !dir ) {
        mkdir(dirName.c_str(), 0777);
    }else {
        closedir(dir);
    }
}

int kvToCSV::outputCSV() {
    
    string outputFileName = this->genCSVFileName();
    cout<<"kvfile name:"<<outputFileName<<endl;
    
    
    KVProvider *kvp = KVProviderFactory::makeKVProvider(); //open KVprovider
    int sz;
    char *s;
    if (!kvp->init(this->inputFilePath)) {
        return 1;
    }
    
    kvFile kf;                                  //open kvFile
    if (!kf.openFile(outputFileName)) {
        cout<<outputFileName<<" create failed."<<endl;
        return 1;
    }
    
    do {
        s = kvp->getKey(sz);
        kf.addHeaderAndWriteToFile(s, sz);
//        cout<<"key: ";
//        show(s, sz);
//        cout<<endl;
        s = kvp->getValue(sz);
        kf.addHeaderAndWriteToFile(s, sz);
//        cout<<"value: ";
//        show(s, sz);
//        cout<<endl;
        
    }while( kvp->next() );
    
    kf.close();                 //close kvFile
    kvp->close();      //close KVprovider
    
    return 0;
}
string kvToCSV::getOSTime() {
    time_t t = time(0);
    char buf[64];
    strftime( buf, sizeof(buf), "%Y_%m_%d_%X",localtime(&t) );
    string result(buf);
    
    return result;
}
string kvToCSV::genCSVFileName() {
    string result;
    string tmpResult;
    tmpResult = this->outputDirectoryPath + "//"  + this->getOSTime();
    int num = 0;
    char buf[64];
    sprintf(buf, "%d",num);
    string temp(buf);
    result = tmpResult + "_" + temp;
    while(this->isFileExisted(result + ".kv")) {
        char buf2[64];
        num++;
        sprintf(buf2, "%d",num);
        string temp2(buf2);
        result = tmpResult + "_" + temp2;
    }
    result = result + ".kv";
    
    return result;
    
}

bool kvToCSV::isFileExisted(string fileName) {
    FILE* fp = fopen(fileName.c_str(), "r");
    if (fp == NULL) {
        return false;
    }
    fclose(fp);
    
    return true;
}

void show(char *z, int n){
     for (int i=0; i<n;i++)
        printf("%x,",z[i]);
}