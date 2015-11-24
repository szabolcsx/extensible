#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <string>
#include <vector>
#include <functional>
#include <map>
#include <type_traits>
#include <typeindex>

#include "shared_object.h"
#include "server.h"
#include "global.h"
#include "iextension.h"

namespace szabi {
    namespace extensible {
        class manager {
        public:
            EXTENSIBLE manager();

            EXTENSIBLE virtual ~manager();

            EXTENSIBLE void load_extension(const std::string &path);

            template<typename S>
            void register_server(server_base &server) {
                // Check if the server is inherited from right type
                static_assert(std::is_base_of<server_base, S>::value, "The class must inherit from Server<>");

                // Store a reference to that server with it's typeid as key
                this->servers.emplace(typeid(typename server::interface_t), std::ref(server));
                // Store the API Version to avoid crashes because of a version mismatch
                this->api_version.emplace(typeid(typename server::interface_t), server::interface_t::api_version());
            }

            template<typename E>
            void attach(const std::string &name) {
                // Check if the extension is inherited from Extensible::IExtension
                // This is required because that class has a static member function which returns the API version used
                // when the extension was compiled
                static_assert(std::is_base_of<iextension, E>::value,
                              "The extension's interface must inherit from Extensible::IExtension");
                std::type_index index = typeid(typename extension::interface_t);

                auto pos = this->servers.find(index);
                if (pos != this->servers.end()) {
                    // If both the server and the extension uses the same API, it could be loaded
                    if (this->api_version[index] == extension::api_version()) {
                        pos->second.get().attach(new E);
                    }
                    else {
                        // API Version mismatch
                        throw std::runtime_error("API Version mismatch when loading " + name);
                    }
                }
            }

        private:
            std::vector<szabi::shared_object> objects;
            std::map<std::type_index, std::reference_wrapper<server_base>> servers;
            std::map<std::type_index, szabi::version> api_version;
        };
    }
}

#endif /* MANAGER_H_INCLUDED */