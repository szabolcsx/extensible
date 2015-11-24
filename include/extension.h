#ifndef EXTENSION_H_INCLUDED
#define EXTENSION_H_INCLUDED

#include <string>
#include <memory>

namespace szabi
{namespace extensible
{
	template <typename I>
	class extension : public I
	{
		public:
			extension() {}
			virtual ~extension() {}

			using interface_t = I;
	};
}
}

#endif /* EXTENSION_H_INCLUDED */