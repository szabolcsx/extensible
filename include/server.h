#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include <vector>
#include <memory>

#include "version.h"

namespace szabi {
    namespace extensible {
        class manager;

        class server_base {
            friend class manager;

        public:
            server_base() {

            }

            virtual ~server_base() {

            }

        protected:
            virtual void attach(void *) = 0;
        };

        template<typename I>
        class server : public server_base {
        public:
            using interface_t = I;
            using interface_p = I *;

            virtual void attached(I *) { }

        private:
            std::vector<std::shared_ptr<I>> extensions;

        protected:
            void attach(void *object) {
                I *implementation = reinterpret_cast<I *>(object);
                this->extensions.emplace_back(implementation);
                this->attached(implementation);
            }
        };
    }
}

#endif /* SERVER_H_INCLUDED */