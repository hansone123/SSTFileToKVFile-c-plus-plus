/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "KVProvider.h"
#include "LevelDBKVProvider.h"
#include "SSTFileKVProvider.h"
#include <iostream>

using namespace std;

KVProvider *KVProviderFactory::makeKVProvider() {
    return new SSTFileKVProvider();
}