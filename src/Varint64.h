/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Varint64.h
 * Author: hanson
 *
 * Created on January 28, 2016, 1:27 PM
 */

#ifndef VARINT64_H
#define VARINT64_H

typedef unsigned char uchar;
typedef unsigned long long int uint64;
namespace Varint{
    int uint64ToVarint(uchar *z,uint64 x);        /* Transfer from x(uint64) to z(Varint), size=return */
    int varintToUint64(uchar *z ,int n ,uint64 &Result); /* Transfer from  z(Varint) to Result(uint64), size=n */
    void varintWrite32(uchar *z, unsigned int y);
};

#endif /* VARINT64_H */

