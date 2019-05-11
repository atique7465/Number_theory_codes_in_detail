#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
using namespace std;
ll a,b,n,t,ck=1,x,y;
ll f[2][2]= {{1,1},{1,0}};
ll ans[2][2]= {{1,0},{0,1}};
ll v[2][1];
ll mod=1000000007;

void mat_pow(ll n)
{
    ll de=0;
    while(n>0)
    {
        if(n%2 == 1)
        {
            if(de==0)
            {
                ans[0][0]=f[0][0];
                ans[0][1]=f[0][1];
                ans[1][0]=f[1][0];
                ans[1][1]=f[1][1];
                de=1;
            }
            else
            {
                ll s=ans[0][0],r=ans[0][1],t=ans[1][0],u=ans[1][1];
                ans[0][0]=((s*f[0][0])%mod+(r*f[1][0])%mod)%mod;
                ans[0][1]=((s*f[0][1])%mod+(r*f[1][1])%mod)%mod;
                ans[1][0]=((t*f[0][0])%mod+(u*f[1][0])%mod)%mod;
                ans[1][1]=((t*f[0][1])%mod+(u*f[1][1])%mod)%mod;
            }
        }
        ll s=f[0][0],r=f[0][1],t=f[1][0],u=f[1][1];

        f[0][0]=((s*s)%mod+(r*t)%mod)%mod;
        f[0][1]=((s*r)%mod+(r*u)%mod)%mod;
        f[1][0]=((t*s)%mod+(u*t)%mod)%mod;
        f[1][1]=((t*r)%mod+(u*u)%mod)%mod;
        n /= 2;
    }
    x=ans[0][0];
    y=ans[0][1];
    ans[0][0]=1;
    ans[0][1]=0;
    ans[1][0]=1;
    ans[1][1]=0;
    f[0][0]=1;
    f[0][1]=1;
    f[1][0]=1;
    f[1][1]=0;
}


int main()
{
    scanf("%lld",&t);
    while(ck<=t)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        v[0][0]=b;
        v[1][0]=a;
        mat_pow(n-1);
        ll res=((x*v[0][0])%mod+(y*v[1][0])%mod)%mod;
        printf("%lld\n",res);
        ck++;
    }
    return 0;
}
