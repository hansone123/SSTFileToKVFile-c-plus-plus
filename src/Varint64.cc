/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Varint64.h"

int Varint::varintToUint64(uchar* z, int n, uint64& Result){
  unsigned int x;
  if( n<1 ) return 0;
  if( z[0]<=240 ){
    Result = z[0];
    return 1;
  }
  if( z[0]<=248 ){
    if( n<2 ) return 0;
    Result = (z[0]-241)*256 + z[1] + 240;
    return 2;
  }
  if( n<z[0]-246 ) return 0;
  if( z[0]==249 ){
    Result = 2288 + 256*z[1] + z[2];
    return 3;
  }
  if( z[0]==250 ){
    Result = (z[1]<<16) + (z[2]<<8) + z[3];
    return 4;
  }
  x = (z[1]<<24) + (z[2]<<16) + (z[3]<<8) + z[4];
  if( z[0]==251 ){
    Result = x;
    return 5;
  }
  if( z[0]==252 ){
    Result = (((uint64)x)<<8) + z[5];
    return 6;
  }
  if( z[0]==253 ){
    Result = (((uint64)x)<<16) + (z[5]<<8) + z[6];
    return 7;
  }
  if( z[0]==254 ){
    Result = (((uint64)x)<<24) + (z[5]<<16) + (z[6]<<8) + z[7];
    return 8;
  }
  Result = (((uint64)x)<<32) +
               (0xffffffff & ((z[5]<<24) + (z[6]<<16) + (z[7]<<8) + z[8]));
  return 9;
}
int Varint::uint64ToVarint(uchar *z, const uint64 x){
  unsigned int w, y;
  if( x<=240 ){
    z[0] = (unsigned char)x;
    return 1;
  }
  if( x<=2287 ){
    y = (unsigned int)(x - 240);
    z[0] = (unsigned char)(y/256 + 241);
    z[1] = (unsigned char)(y%256);
    return 2;
  }
  if( x<=67823 ){
    y = (unsigned int)(x - 2288);
    z[0] = 249;
    z[1] = (unsigned char)(y/256);
    z[2] = (unsigned char)(y%256);
    return 3;
  }
  y = (unsigned int)x;
  w = (unsigned int)(x>>32);
  if( w==0 ){
    if( y<=16777215 ){
      z[0] = 250;
      z[1] = (unsigned char)(y>>16);
      z[2] = (unsigned char)(y>>8);
      z[3] = (unsigned char)(y);
      return 4;
    }
    z[0] = 251;
    varintWrite32(z+1, y);
    return 5;
  }
  if( w<=255 ){
    z[0] = 252;
    z[1] = (unsigned char)w;
    varintWrite32(z+2, y);
    return 6;
  }
  if( w<=65535 ){
    z[0] = 253;
    z[1] = (unsigned char)(w>>8);
    z[2] = (unsigned char)w;
    varintWrite32(z+3, y);
    return 7;
  }
  if( w<=16777215 ){
    z[0] = 254;
    z[1] = (unsigned char)(w>>16);
    z[2] = (unsigned char)(w>>8);
    z[3] = (unsigned char)w;
    varintWrite32(z+4, y);
    return 8;
  }
  z[0] = 255;
  varintWrite32(z+1, w);
  varintWrite32(z+5, y);
  return 9;
}

void Varint::varintWrite32(uchar *z, unsigned int y) { 
  z[0] = (unsigned char)(y>>24);
  z[1] = (unsigned char)(y>>16);
  z[2] = (unsigned char)(y>>8);
  z[3] = (unsigned char)(y);
}