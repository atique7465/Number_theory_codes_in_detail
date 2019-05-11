// CPP program to count the
// number of numbers in range
// 1-M that are divisible by
// given N prime numbers
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// function to count the number
// of numbers in range 1-M that
// are divisible by given N
// prime numbers
int count(ll a[], ll m, ll n)
{
    ll odd = 0, even = 0;
    ll counter, i, j, p = 1;
    ll pow_set_size = (1 << n);

    // Run from counter 000..0 to 111..1
    for (counter = 1; counter < pow_set_size;
                                   counter++)
    {
        p = 1;
        for (j = 0; j < n; j++)
        {

            // Check if jth bit in the
            // counter is set If set
            // then pront jth element from set
            if (counter & (1 << j))
            {
                p *= a[j];
            }
        }

        // if set bits is odd, then add to
        // the number of multiples
        if (__builtin_popcount(counter) & 1)
            odd += (m / p);
        else
            even += m / p;
    }

    return odd - even;
}
// Driver Code
int main()
{
    ll a[] = {2,5};
    ll m = 1000;
    ll n = sizeof(a) / sizeof(a[0]);
    cout << count(a, m, n);
    return 0;
}

