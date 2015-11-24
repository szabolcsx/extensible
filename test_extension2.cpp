#include <Extensible\manager.h>
#include <Application\itest.h>
#include <Extensible\extension.h>

#include <iostream>

class test_extension2 : public szabi::extensible::extension<itest2>
{
public:
	test_extension2()
	{
		std::cout << "test_extension2 constructed" << std::endl;
	}
	virtual ~test_extension2() {}

	void f()
	{
		std::cout << "test_extension2::f() ";
	}

	void g()
	{
		std::cout << "test_extension2::g()" << std::endl;
	}
};

#include <iostream>

extern "C" __declspec(dllexport) void attach(szabi::extensible::manager& manager)
{
	manager.attach<test_extension2>("test_extension2");
}