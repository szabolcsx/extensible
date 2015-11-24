#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#ifdef _WINDLL
#define BUILDING_EXTENSIBLE
#endif

#ifdef BUILDING_EXTENSIBLE
#define EXTENSIBLE	__declspec(dllexport)
#else
#define EXTENSIBLE    __declspec(dllimport)
#endif

#endif /* GLOBAL_H_INCLUDED */