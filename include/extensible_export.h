
#ifndef EXTENSIBLE_H
#define EXTENSIBLE_H

#ifdef EXTENSIBLE_STATIC_DEFINE
#  define EXTENSIBLE
#  define EXTENSIBLE_NO_EXPORT
#else
#  ifndef EXTENSIBLE
#    ifdef extensible_EXPORTS
        /* We are building this library */
#      define EXTENSIBLE __declspec(dllexport)
#    else
        /* We are using this library */
#      define EXTENSIBLE __declspec(dllimport)
#    endif
#  endif

#  ifndef EXTENSIBLE_NO_EXPORT
#    define EXTENSIBLE_NO_EXPORT 
#  endif
#endif

#ifndef EXTENSIBLE_DEPRECATED
#  define EXTENSIBLE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef EXTENSIBLE_DEPRECATED_EXPORT
#  define EXTENSIBLE_DEPRECATED_EXPORT EXTENSIBLE EXTENSIBLE_DEPRECATED
#endif

#ifndef EXTENSIBLE_DEPRECATED_NO_EXPORT
#  define EXTENSIBLE_DEPRECATED_NO_EXPORT EXTENSIBLE_NO_EXPORT EXTENSIBLE_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define EXTENSIBLE_NO_DEPRECATED
#endif

#endif
