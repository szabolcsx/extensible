#pragma once

#ifdef _WINDLL
#define BUILDING_EXTENSIBLE
#endif

#ifdef BUILDING_EXTENSIBLE
#define EXTENSIBLE	__declspec(dllexport)
#else
#define EXTENSIBLE	__declspec(dllimport)
#endif
