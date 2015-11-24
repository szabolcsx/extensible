#include "version.h"

#include <tuple>

EXTENSIBLE bool szabi::operator>(const version& a, const version& b)
{
	return std::tie(a.major, a.minor) > std::tie(b.major, b.minor);
}

EXTENSIBLE bool szabi::operator<(const version& a, const version& b)
{
	return std::tie(a.major, a.minor) < std::tie(b.major, b.minor);
}

EXTENSIBLE bool szabi::operator>=(const version& a, const version& b)
{
	return std::tie(a.major, a.minor) >= std::tie(b.major, b.minor);
}

EXTENSIBLE bool szabi::operator<=(const version& a, const version& b)
{
	return std::tie(a.major, a.minor) <= std::tie(b.major, b.minor);
}

EXTENSIBLE bool szabi::operator==(const version& a, const version& b)
{
	return std::tie(a.major, a.minor) == std::tie(b.major, b.minor);
}

EXTENSIBLE bool szabi::operator!=(const version& a, const version& b)
{
	return std::tie(a.major, a.minor) != std::tie(b.major, b.minor);
}