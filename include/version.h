#pragma once
#include "global.h"

namespace szabi
{
	struct EXTENSIBLE version
	{
		int major;
		int minor;
	};

	EXTENSIBLE bool operator > (const version&, const version&);
	EXTENSIBLE bool operator < (const version&, const version&);
	EXTENSIBLE bool operator >= (const version&, const version&);
	EXTENSIBLE bool operator <= (const version&, const version&);
	EXTENSIBLE bool operator == (const version&, const version&);
	EXTENSIBLE bool operator != (const version&, const version&);
}