/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cc
 * Author: hansone123
 *
 * Created on March 1, 2016, 4:21 AM
 */

#include <cstdlib>
#include <iostream>
#include "../src/FileObserver.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    FileObserver *sstfileObserver = new FileObserver();
    if (!sstfileObserver->setValidDirectoryPath("/tmp/SSTFiles"))
        return 1;
    sstfileObserver->keepWatchOnDirectoryAndDoJob();
    
    delete sstfileObserver;
    
    return 0;
}

