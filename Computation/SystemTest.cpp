#include "System.hpp"
#include "Particle.hpp"
#include <assert.h>

int main()
{
	{
		System s;
		assert(s.sys.size == 0);
	}
}