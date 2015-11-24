#include <manager.h>
#include "itest.h"

#include <iostream>

class test1 : public szabi::extensible::server<itest1>
{
public:
	test1()
	{

	}

	~test1()
	{

	}

    void attached(test::interface_p impl)
	{
		std::cout << "Test: ";
		impl->f();
	}
};

class test2 : public szabi::extensible::server<itest2>
{
public:
	test2()
	{

	}

	~test2()
	{

	}

    void attached(test2::interface_p impl)
	{
		std::cout << "Test2: ";
		impl->f();
		impl->g();
	}
};


int main()
{
	try
	{
		test1 test1;
		test2 test2;
		szabi::extensible::manager manager;
		manager.register_server<test1>(test1);
		manager.register_server<test2>(test2);
		manager.load_extension("TestExtension1.dll");
		manager.load_extension("TestExtension2.dll");
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cin.get();

	return 0;
}
