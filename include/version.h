#ifndef VERSION_H_INCLUDED
#define VERSION_H_INCLUDED

#include "extensible_export.h"

namespace szabi {
    struct EXTENSIBLE version {
        int major;
        int minor;
    };

    EXTENSIBLE bool operator>(const version &, const version &);

    EXTENSIBLE bool operator<(const version &, const version &);

    EXTENSIBLE bool operator>=(const version &, const version &);

    EXTENSIBLE bool operator<=(const version &, const version &);

    EXTENSIBLE bool operator==(const version &, const version &);

    EXTENSIBLE bool operator!=(const version &, const version &);
}

#endif /* VERSION_H_INCLUDED */