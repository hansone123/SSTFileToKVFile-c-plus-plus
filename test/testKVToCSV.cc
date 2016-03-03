/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testKVToCSV.cc
 * Author: hanson
 *
 * Created on January 28, 2016, 12:26 AM
 */

#include <cstdlib>
#include <iostream>
#include "../src/KVToCSV.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    kvToCSV *kvt = new kvToCSV();
    kvt->setInputFilePath("testdb");
    kvt->setOutputDirectory("/tmp/KVoutput/");
    if (kvt->outputCSV() != 0 ) {
        cout<<"output kvfile failed!";
    }else {
        cout<<"output kvfile success!";
    }
    return 0;
}

