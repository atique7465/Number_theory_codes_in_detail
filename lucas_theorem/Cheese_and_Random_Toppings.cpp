#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v;
ll arr[2010][2010];
ll N=110,t,i,j,n,r,m;
ll status[110];
void prime()
{
    ll sqrtN;
    sqrtN = int( sqrt((double) N ));
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(2);
    int ck=1;
    for( i = 3; i <= N; i += 2 )
    {
        if( status[i] == 0 )
        {
            v.push_back(i);
        }
    }
}

ll exeuclid(ll a,ll b,ll *x,ll *y);
ll inv(ll a,ll b)
{
    ll x,y;
    ll g=exeuclid(a,b,&x,&y);
    return ((x%m)+m)%m;
}
ll exeuclid(ll a,ll b,ll *x,ll *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    ll x1,y1;
    ll g=exeuclid(b%a,a,&x1,&y1);
    *x=y1-((b/a)*x1);
    *y=x1;
    return g;
}

ll crt(vector<ll>a,vector<ll>p,ll m)
{
    ll q=0,mi;
    for(ll i=0; i<p.size(); i++)
    {
        mi=m/p[i];
        q+=mi*inv(mi,p[i])*a[i];
    }
    return q;
}

ll comb(ll n,ll r,ll mod)
{
    ll ans;
    if(r==0||r==n)
        return 1;
    if(r==1)
        return n;
    if(r<0 || r>n)
        return 0;
    if(arr[n][r]!=0)
        return arr[n][r];

    arr[n][r]=(comb(n-1,r-1,mod)+comb(n-1,r,mod));
    return arr[n][r];
}

ll lucas(ll n,ll r,ll p)
{
    ll res=1;
    while(n>0)
    {
        res=(res*comb(n%p,r%p,p))%p;
        r/=p;
        n/=p;
    }
    return res;
}

ll ncr(ll n,ll r,ll m)
{
    vector<ll>p;
    vector<ll>a;
    for(i=0; i<v.size(); i++)
    {
        if(m%v[i]==0){
            p.push_back(v[i]);}
    }
    for(i=0; i<p.size(); i++)
    {
        a.push_back(lucas(n,r,p[i]));
    }
    return crt(a,p,m)%m;
}

int main()
{
    prime();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&r,&m);
        printf("%lld\n",ncr(n,r,m));
    }
    return 0;
}
