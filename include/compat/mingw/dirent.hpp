// BK - MinGW dirent is super broken, using MSVC compatibility one...
#ifndef _DIRENT_H_
#define _DIRENT_H_
#ifdef __MINGW32__
#include "../msvc/dirent.hpp"
#else 
#include <dirent.h>
#endif
#endif // _DIRENT_H_
