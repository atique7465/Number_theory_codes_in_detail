#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x, ll y, ll p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
bool miillerTest(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);

    // Compute a^d % n
    ll x = power(a, d, n);

    if (x == 1  || x == n-1)
        return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    // Return composite
    return false;
}
bool isPrime(ll n, ll k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (ll i = 0; i < k; i++)
        if (miillerTest(d, n) == false)
            return false;

    return true;
}

int main()
{
    ll ans=0,d,m,n,k = 4;

    cin>>n>>m;
    if(n<=3&&m>=5)
        ans++;
    if(n%6==0)
        d=n+6;
    else
    {
        for(ll i=n; i<m; i++)
            if(i%6==0)
            {
                d=i;
                break;
            }
    }
    for(ll i=d; i<m; i+=6)
    {
        if(isPrime(i-1,k)&&(isPrime(i+1,k)))
                ans++;
    }
    cout<<ans;
return 0;
}
