#include <cmath>
#include "primes.hpp"

using namespace std;

namespace
{
    bool divides(int a, int b)
    {
        return b % a == 0;
    }
}

namespace primes
{
    bool is_prime(unsigned int n)
    {
        if (n < 2)
        {
            return false;
        }

        for (auto i = 2u; i <= static_cast<unsigned int>(sqrt(n)); ++i)
        {
            if (divides(i, n))
            {
                return false;
            }
        }

        return true;
    }
}