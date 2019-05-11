#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
using namespace std;
ll mod=1000000000;
vector<ll>vx,vy;
ll a,b,c,d,e,f,g,h,n,t,ck=1;

ll xn(ll n);
ll pow(ll a, ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans=(ans*a);
            if(ans>mod) ans%=mod;
        }
        a = (a*a);
        if(a>mod) a%=mod;
        b /= 2;
    }
    return ans;
}

ll yn(ll n)
{
    ll y;
    if(n<0) return 1;
    else
    {
        y=(yn(n-e)+xn(n-f)+xn(n-g)+((n%mod)*pow(h,n))%mod)%mod;
        return y;
    }
}

ll xn(ll n)
{
    ll x;
    if(n<0) return 1;
    else
    {
        x=(xn(n-a)+yn(n-b)+yn(n-c)+((n%mod)*pow(d,n))%mod)%mod;
        return x;
    }
}

int main()
{
    scanf("%lld",&t);
    while(ck<=t)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g,&h,&n);
        ll x=xn(n);
        ll y=yn(n);
        printf("%lld %lld\n",x,y);
        ck++;
    }
    return 0;
}
