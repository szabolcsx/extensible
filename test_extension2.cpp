#include <szabi/extensible.h>
#include "itest.h"

#include <iostream>
#include <szabi/extensible/manager.h>
#include <szabi/extensible/extension.h>

class test_extension2 : public szabi::extensible::extension<itest2> {
public:
    test_extension2() {
        std::cout << "test_extension2 constructed" << std::endl;
    }

    virtual ~test_extension2() { }

    void f() {
        std::cout << "test_extension2::f() ";
    }

    void g() {
        std::cout << "test_extension2::g()" << std::endl;
    }
};

EXTENSION_ATTACHER void attach(szabi::extensible::manager &manager) {
    try {
        manager.attach<test_extension2>("test_extension2");
    }
    catch (...) {

    }
}