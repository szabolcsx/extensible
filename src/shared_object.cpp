#ifdef _WIN32
#   include "windows/shared_object.cpp.inc"
#elif linux
#   include "unix/shared_object.cpp.inc"
#endif