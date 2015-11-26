#include <szabi/extensible/shared_object.h>
#include <dlfcn.h>

#include <iostream>

namespace szabi {
    shared_object::shared_object(const std::string &path) : object(dlopen(path.c_str(), RTLD_LAZY),
                                                                   [](void *object) {
                                                                       if (object)
                                                                           dlclose(object);
                                                                   }) {
        if (!this->object) {
            throw std::runtime_error("Unable to open library.");
        }

        this->object_path = path;
    }

    shared_object::~shared_object() {
    }

    std::string shared_object::path() const {
        return this->object_path;
    }

    void *shared_object::get_raw_symbol(const std::string &name) {
        void *address = nullptr;

        if (!this->object) {
            throw std::runtime_error("Object not loaded.");
        }

        if (name.empty()) {
            throw std::runtime_error("Symbol name can't be empty.");
        }

        address = dlsym(this->object.get(), name.c_str());

        if (address == nullptr) {
            throw std::runtime_error("Unable to get symbol.");
        }

        return address;
    }
}
