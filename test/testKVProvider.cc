/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <map>
#include "../src/KVProvider.h"
#include "leveldb/db.h"
#include "leveldb/table.h"
#include "leveldb/db.h"
#include "leveldb/env.h"

using namespace std;

void show(char *z, int n);

int main(int argc, char** argv){

	for(int i = 0; i < 1; i++){
		int j = 10;
		KVProvider *kvp = KVProviderFactory::makeKVProvider();
		int sz;
		char *s;
		if(kvp->init("000005.ldb")){
			cout << i << endl;
			do{
				s = kvp->getKey(sz);
				cout << "key: ";
				show(s, sz);
				cout << endl;
				s = kvp->getValue(sz);
				cout << "value: ";
				show(s, sz);
				cout << endl << endl;

			} while(kvp->next());
			kvp->close();
		}
	}
}

void show(char *z, int n){
	for(int i = 0; i < n; i++)
		printf("%c,", z[i]);
}