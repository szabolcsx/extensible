#ifndef IEXTENSION_H_INCLUDED
#define IEXTENSION_H_INCLUDED

#include "version.h"

namespace szabi {
    namespace extensible {
        class iextension {
        public:
            static szabi::version api_version();
        };
    }
}

#endif /* IEXTENSION_H_INCLUDED */