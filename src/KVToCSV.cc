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

using namespace std;

void show(char *z, int n);

kvToCSV::kvToCSV() {
    this->num = 1;
    this->nowTime = this->getTime();
}
bool kvToCSV::init() {
    setInputPath("testdb");
    setOutputPath("output");
    return true;
}
void kvToCSV::setInputPath(string p) {
    this->inPath = p;
}
void kvToCSV::setOutputPath(string p) {
    this->outPath = p;
}
string kvToCSV::getInputFile() {
    return this->inPath + "";
}

int kvToCSV::outputCSV() {
    
    KVProvider *kvp = KVProvider::KVPfactory();
    int sz;
    char *s;
    if (!kvp->init(this->getInputFile()))
        return 1;
    do {
//        s = kvp->getKey(sz);
//        cout<<"key: ";
//        show(s, sz);
//        cout<<endl;
//        s = kvp->getValue(sz);
//        cout<<"value: ";
//        show(s, sz);
//        cout<<endl;
        
    }while( kvp->next() );
    
    cout<<"csv name:"<<this->genCSVFileName()<<endl;
    cout<<"outPath:"<<this->outPath<<endl;
    KVProvider::Kill(kvp);
    
    return 0;
}
string kvToCSV::getTime() {
    time_t t = time(0);
    char buf[64];
    strftime( buf, sizeof(buf), "%Y/%m/%d/%X",localtime(&t) );
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
    sprintf(str, "/%d", n);
    result.assign(this->nowTime);
    result.append(str);
    
    return result;
    
}


void show(char *z, int n){
     for (int i=0; i<n;i++)
        printf("%x,",z[i]);
}