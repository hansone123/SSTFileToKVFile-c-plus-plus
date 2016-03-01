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
#include "../src/FileObserver.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    FileObserver *fs = new FileObserver();
    if (!fs->setValidDirectoryPath("/tmp/SSTFiles"))
        return 1;
    fs->keepWatchOnDirectoryAndDoJob();
    delete fs;
    return 0;
}

