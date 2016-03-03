/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "../src/KVProvider.h"

using namespace std;

void show(char *z, int n);

int main(int argc, char** argv) {    
    
    for (int i=0; i<10; i++) {
        KVProvider *kvp = KVProviderFactory::makeKVProvider();
        int sz;
        char *s;
        if (kvp->init("testdb")) {
            cout<<i<<endl;
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
        kvp->close();
        }        
    }    
}

void show(char *z, int n){
     for (int i=0; i<n;i++)
        printf("%x,",z[i]);
}