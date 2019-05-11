#include <stdio.h>
#include <iostream>
#include <climits>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

#define fr first
#define sd second

#define ftf 1001005

ll phi[ftf+100];
unsigned int p[ftf/32 + 100]; //unsigned int gives 32 bits
int prime[ftf/2];

void euler_phi_sieve()
{
    long long sq, a, b, flag = 0, i, j, k;

    for (i = 0; i < ftf; i++)
        phi[i] = i;

    sq = (long long) (sqrt((double) ftf) + 1.0);

    k = 0;

    for (i = 2; i <= sq ; i+=2)
    {
        if ((p[i>>5]&(1LL<<(i&31))) == 0) //bitwise sieve
        {
            prime[k++] = i;
            for (j = i; j <= ftf; j+=i)
            {
                if (j != i)
                    p[j>>5] = p[j>>5]|(1LL<<(j&31));
                phi[j] = phi[j]-phi[j]/i;
            }
        }
        if (i == 2)
            i = 1;
    }

    for (; i <= ftf; i+=2)
    {
        if ((p[i>>5]&(1<<(i&31))) == 0)
        {
            prime[k++] = i;
            for (j = i; j <= ftf; j+=i)
            {
                phi[j] = phi[j]-phi[j]/i;
            }
        }
    }
}


ll fact[1000005], fact1[1000005];

ll s2, s1;

ll ex_eucl(ll x, ll y)
{
    ll q, r, temp;

    q = x/y;

    r = x - q*y;

    temp = s2 - q*s1;
    s2 = s1;
    s1 = temp;

    if (r == 1)
        return s1;
    else return ex_eucl(y, r);
}

ll gcd(ll a, ll b)
{
    if (a%b == 0)
        return b;

    return gcd(b, a%b);
}

ll a1, m1; //m1 should be initialized as -1 first

void CRT(ll a2, ll m2)
{
    ///CRT, this will find Z such that Z%m1 = a1 and Z%m2 = a2, the answer will be saved in a1
    ///this CRT uses extended euclid, so works for coprimes as well

    s2 = 1;
    s1 = 0;

    ll k = ex_eucl(m1, m2);

    ll gc = gcd(m2,m1);

    gc = m2/gc;

    k = (k%gc + gc)%gc; ///here gcd is 1, generally we'd have to mod by n/gcd

    k = ((a2-a1)*k)%gc;

    ll lcm = m1*(m2/gcd(m1,m2));

    a1 = (a1 + (k*m1)%lcm)%lcm;

    if (a1 < 0)
        a1 = (a1 + lcm)%lcm;

    m1 = lcm;

}

ll pwr(ll b, ll p, ll m)
{
    if (p == 0)
        return 1;

    ll x = pwr(b, p/2, m);
    x = (x*x)%m;

    if (p%2 == 0)
        return x;
    else return (b*x)%m;
}

ll nfactwithoutp(ll n, ll p, ll m) ///this has log_primeno(n) complexity
{

    if (n < p)
    {
        return fact1[n];
    }

    /// n!! = (m-1)!^(n/m)*( (n/p)!! )*(n%m)! here, x! has no p in it
    ll x = n/p;

    ll z = nfactwithoutp(x, p, m);

    z = (z*fact[n%m])%m;


    z = (z*pwr(fact[m-1], n/m, m))%m;

    return z;
}

ll nCrmodprimepower(ll n, ll r, ll pp, ll primeno) /// the complexity here is like O(pp)
{
    /// nCr = n!/(r!(n-r)!), will split all primeno from them manually first
    /// let n!! = n! without any primeno, pb will be primeno^b where b = frequency of primeno in nCr

    ll pb, b = 0, nf, nrf, rf;

    ll nr = n - r;

    ll temp = n;

    while(temp != 0)
    {
        b += temp/primeno;
        temp /= primeno;
    }

    temp = r;

    while(temp != 0)
    {
        b -= temp/primeno;
        temp /= primeno;
    }

    temp = nr;

    while(temp != 0)
    {
        b -= temp/primeno;
        temp /= primeno;
    }

    pb = pwr(primeno, b, pp);

    if (pb == 0)
        return 0;

    fact[0] = 1;

    for (ll i = 1; i <= pp; i++)
    {
        ll tmp = i;

        if(tmp%primeno == 0)
        {
            fact[i] = fact[i-1];
            continue;
        }

        fact[i] = (fact[i-1]*tmp)%pp;
    }

    fact1[0] = 1;

    for (ll i = 1; i <= primeno; i++)
    {
        fact1[i] = (fact1[i-1]*i)%pp;
    }

    nf = nfactwithoutp(n, primeno, pp); // n!!

    rf = nfactwithoutp(r, primeno, pp);

    rf = pwr(rf, phi[pp]-1, pp);

    nrf = nfactwithoutp(nr, primeno, pp);

    nrf = pwr(nrf, phi[pp]-1, pp);

    return (((((pb*nf)%pp)*rf)%pp)*nrf)%pp;
}

ll nCr(ll n, ll r, ll m) //returns nCr mod m for n, r <= 10^18 and small any m using nCr mod prime^a and CRT
{
    //first, m is prime factorized

    //for m = p1^a1*p2^a2*p3^a3... we will find nCr mod pi^ai for each pi

    //then, CRT will be used to combine result


    //complexity is like no_of_primefactors*(prime factor ^ frequency + log_prime(n)), no_of_primefactors can't be that big for numbers below 10^9 or so
   // cout<<n<<" "<<r<<" "<<m<<endl;
    if (n == r || r == 0)
        return 1;


    ll temp = m;

    ll pp;

    m1 = -1;

    for (ll i = 0; prime[i]*prime[i] <= temp; i++)
    {
        pp = 1;

        while(temp%prime[i] == 0)
        {
            pp *= prime[i];
            temp /= prime[i];
        }

        if (pp > 1)
        {
            ///gonna find nCr mod prime[i]^freq now with following function, prime[i]^freq = pp

            if (m1 == -1) ///no answer in CRT yet
            {
                m1 = pp;
                a1 = nCrmodprimepower(n, r, pp, prime[i]);
            }
            else
            {
                ll a2 = nCrmodprimepower(n, r, pp, prime[i]);

                ll m2 = pp;

                CRT(a2, m2);
            }
        }
    }


    if (temp != 1)
    {
        pp = temp;
        if (m1 == -1)
        {
            m1 = pp = temp;
            a1 = nCrmodprimepower(n, r, pp, temp);
        }
        else
        {
            ll a2 = nCrmodprimepower(n, r, pp, temp);

            ll m2 = temp;

            CRT(a2, m2); // answer is saved in a1
        }
    }
    return a1;
}

int main ()
{
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n, d;

    //euler totient

    euler_phi_sieve();

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(k);
        sl(m);

        d = n/k;

        if (n%k != 0)
            d++;

        printf("%lld %lld\n", d, nCr(d-1+d*k-n, d-1, m));
    }
    return 0;
}
