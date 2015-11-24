#include <Extensible\manager.h>
#include <Application\itest.h>
#include <Extensible\extension.h>

#include <Extensible/version.h>

#include <iostream>

class test_extension1 : public szabi::extensible::extension<itest1>
{
public:
	test_extension1()
	{
		std::cout << "test_extension1 constructed" << std::endl;
	}
	virtual ~test_extension1() {}

	void f()
	{
		std::cout << "test_extension1::f()" << std::endl;
	}
};

extern "C" __declspec(dllexport) void attach(szabi::extensible::manager& manager)
{
	try
	{
		manager.attach<test_extension1>("test_extension1");
	}
	catch (...)
	{

	}
}
