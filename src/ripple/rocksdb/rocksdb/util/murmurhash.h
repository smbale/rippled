//  Copyright (c) 2013, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the root directory of this source tree. An additional grant
//  of patent rights can be found in the PATENTS file in the same directory.
//
/*
  Murmurhash from http://sites.google.com/site/murmurhash/

  All code is released to the public domain. For business purposes, Murmurhash is
  under the MIT license.
*/
#pragma once
#include <stdint.h>

#if defined(__x86_64__)
#define MURMUR_HASH MurmurHash64A
uint64_t MurmurHash64A ( const void * key, int len, unsigned int seed );
#define MurmurHash MurmurHash64A
typedef uint64_t murmur_t;

#elif defined(__i386__)
#define MURMUR_HASH MurmurHash2
unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed );
#define MurmurHash MurmurHash2
typedef unsigned int murmur_t;

#else
#define MURMUR_HASH MurmurHashNeutral2
unsigned int MurmurHashNeutral2 ( const void * key, int len, unsigned int seed );
#define MurmurHash MurmurHashNeutral2
typedef unsigned int murmur_t;

#endif