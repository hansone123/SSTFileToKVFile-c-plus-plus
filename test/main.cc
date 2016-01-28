/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cc
 * Author: hanson
 *
 * Created on January 28, 2016, 1:41 PM
 */

#include <cstdlib>
#include "../src/Varint64.h"
#include <cstdio>

using namespace std;

void show(char *z, int n);
/*
 * 
 */
int main(int argc, char** argv) {
    uint64 input = 10;
    uchar *output;
    output = (uchar*)malloc(sizeof(uchar)*9);
    
    int osz = Varint::uint64ToVarint(output, input);
    show((char*)output, osz);
    return 0;
}

void show(char *z, int n){
     for (int i=0; i<n;i++)
        printf("%x,",z[i]);
}