#include <szabi/extensible.h>
#include "itest.h"

#include <iostream>

class test1 : public szabi::extensible::server<itest1> {
public:
    test1() {

    }

    ~test1() {

    }

    void attached(test1::interface_p impl) {
        std::cout << "Test1: ";
        impl->f();
    }
};

class test2 : public szabi::extensible::server<itest2> {
public:
    test2() {

    }

    ~test2() {

    }

    void attached(test2::interface_p impl) {
        std::cout << "Test2: ";
        impl->f();
        impl->g();
    }
};


int main() {
    try {
        test1 t1;
        test2 t2;
        szabi::extensible::manager manager;
        manager.register_server<test1>(t1);
        manager.register_server<test2>(t2);
#ifdef _WIN32
        manager.load_extension("libtest_extension1.dll");
        manager.load_extension("libtest_extension2.dll");
#elif linux
        manager.load_extension("./libtest_extension1.so");
        manager.load_extension("./libtest_extension2.so");
#endif
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
