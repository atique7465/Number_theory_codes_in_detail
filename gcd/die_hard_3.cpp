#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(int a, int b)
{
    if(b==0) return a;
    else
    {
        a%=b;
        return gcd(b,a);
    }
}

int main()
{
    ll a,b,x,y;
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    ll x1=x/gcd(x,y);
    ll y1=y/gcd(x,y);
    ll ans=min(a/x1,b,y1);
    printf("%lld",ans);
    return 0;
}
