/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "KVProvider.h"
#include "LevelDBKVProvider.h"
#include <iostream>

using namespace std;

KVProvider *KVProvider::KVPfactory() {
    return new LevelDBKVProvider();
}
void KVProvider::Kill(KVProvider *kvp) {
    LevelDBKVProvider *lkvp = (LevelDBKVProvider*)kvp;
    delete lkvp;
}