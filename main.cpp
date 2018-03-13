#include <iostream>
#include <string>

#include "primes_in_range.hpp"

using namespace std;

namespace
{
    struct usage_exception {};

    //! Cast `int` to `unsigned int` or throw `invalid_argument` if it is negative
    unsigned int to_uint(int n)
    {
        if (n < 0)
        {
            const auto msg = to_string(n) + " is negative.";
            throw invalid_argument{ msg };
        }

        return static_cast<unsigned int>(n);
    }
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 3)
        {
            throw usage_exception{};
        }

        const auto start_signed = stoi(argv[1]);
        const auto start = to_uint(start_signed);

        const auto end_signed = stoi(argv[2]);
        const auto end = to_uint(end_signed);

        cout << "Primes in range [" << start << ", " << end << "]:" << endl;
        for (auto n : primes_in_range(start, end))
        {
            cout << n << endl;
        }

        return 0;
    }
    catch (usage_exception&)
    {
        cerr << "Usage: primes_in_range <begin> <end>" << endl;
        return 1;
    }
    catch (invalid_argument& ia)
    {
        cerr << "[Error] " << ia.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "[Error] an unknown error occurred" << endl;
        return -1;
    }
}