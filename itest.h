#ifndef ITEST_H_INCLUDED
#define ITEST_H_INCLUDED

#include <szabi/extensible/iextension.h>

class itest1 : public szabi::extensible::iextension {
public:
    virtual void f() = 0;

    static szabi::version api_version() {
        return {1, 0};
    }
};

class itest2 : public szabi::extensible::iextension {
public:
    virtual void f() = 0;

    virtual void g() = 0;

    static szabi::version api_version() {
        return {1, 1};
    }
};

#endif /* ITEST_H_INCLUDED */