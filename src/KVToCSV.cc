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
    this->nowTime = this->getTime();
}
bool kvToCSV::init() {
    setInputPath("testdb");
    setOutputFolder("/tmp/KVoutput/");
    return true;
}
void kvToCSV::setInputPath(string p) {
    this->inPath = p;
}
void kvToCSV::setOutputFolder(string p) {
    this->createOuputFolder(p);
    this->outPath = p;
}
void kvToCSV::createOuputFolder(string p) {
    DIR *dir;
    if ( !(dir = opendir(p.c_str())) )
        mkdir(p.c_str(), 0777);
}
string kvToCSV::getInputFile() {
    return this->inPath + "";
}

int kvToCSV::outputCSV() {
    
    string file_name = this->genCSVFileName();
    string out_path = this->outPath + file_name;
    cout<<"kvfile name:"<<file_name<<endl;
    cout<<"outPath:"<<out_path<<endl;
    
    kvFile kf;                                  //open kvFile
    if (!kf.openFile(out_path))
        return 1;
    
    KVProvider *kvp = KVProvider::KVPfactory(); //open KVprovider
    int sz;
    char *s;
    if (!kvp->init(this->getInputFile()))
        return 1;
    do {
        s = kvp->getKey(sz);
        kf.writeToFile(s, sz);
//        cout<<"key: ";
//        show(s, sz);
//        cout<<endl;
        s = kvp->getValue(sz);
        kf.writeToFile(s, sz);
//        cout<<"value: ";
//        show(s, sz);
//        cout<<endl;
        
    }while( kvp->next() );
    
    KVProvider::Kill(kvp);      //close KVprovider
    kf.close();                 //close kvFile
    
    return 0;
}
string kvToCSV::getTime() {
    time_t t = time(0);
    char buf[64];
    strftime( buf, sizeof(buf), "%Y_%m_%d_%X",localtime(&t) );
    string result;
    result.assign(buf);
    return result;
}
string kvToCSV::genCSVFileName() {
    
    string result;
    string time = this->getTime();
    string curtime = this->nowTime;
    
    if ( time.compare(curtime)>0 ) {
        this->num = 1;
        this->nowTime = time;
    }
        
    int n = this->num;
    this->num++;
    
    char str[256];
    sprintf(str, "_%d", n);
    result.assign(this->nowTime);
    result.append(str);
    result.append(".kv");
    
    return result;
    
}


void show(char *z, int n){
     for (int i=0; i<n;i++)
        printf("%x,",z[i]);
}