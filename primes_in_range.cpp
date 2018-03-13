#include "primes.hpp"
#include "primes_in_range.hpp"

using namespace std;

//! Find all primes in the range `[first, last]` using a single-threaded trial division algorithm.
//! If `first > last`, the range is considered empty and an empty vector will be returned.
vector<unsigned int> primes_in_range(unsigned int first, unsigned int last)
{
    vector<unsigned int> result{};
    for (auto i = first; i <= last; ++i)
    {
        if (primes::is_prime(i))
        {
            result.push_back(i);
        }
    }

    return result;
}
