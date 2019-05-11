#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int>v,q;
ll N = 500;
ll status[500];
ll nff[100010][10];
ll nff1[100010][10];
ll vf[100010];
ll n,k,l,m,res,i,t,c=1,j;
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

ll mod_pow(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans*=a;
            if(ans>n)
                ans%=n;
        }
        a=a*a;
        if(a>n)
            a%=n;
        b/=2;
    }
    return ans;
}

void prime_factorise(ll p)
{
    ll s=0;
    for(j=0; v[j]*v[j]<=p; j++)
    {
        if(p%v[j]==0)
        {
            nff[i][s]=v[j];
            ll d=0;
            while(p%v[j]==0)
            {
                p/=v[j];
                d++;
            }
            nff1[i][s]=d;
            s++;
        }
    }
    if(p>1)
    {
        nff[i][s]=p;
        nff1[i][s]=1;
    }
}

int main()
{
    prime();
    for(i=2; i<=100010; i++)
    {
        prime_factorise(i);
    }
    scanf("%lld",&t);
    while(c<=t)
    {
        res=0;
        scanf("%lld%lld%lld%lld",&n,&k,&l,&m);
        if(m==0)
        {
            res=mod_pow(k,l);
        }
        else
        {
            ll k1,k2;
            if(k%2==0)
            {
                k1=mod_pow(k,l-1)*(k/2);
                k2=mod_pow(k-1,m);
            }
            else
            {
                k1=mod_pow(k-1,m-1)*((k-1)/2);
                k2=mod_pow(k,l);
            }
            res=((k1%n)*(k2%n))%n;
            for(i=m+1; i<=l; i++)
            {
                    for(j=0; j<=10; j++)
                    {
                        if(vf[nff[i][j]]==0)
                            q.push_back(nff[i][j]);
                        vf[nff[i][j]]=vf[nff[i][j]]+nff1[i][j];
                        if(nff[i][j+1]==0)
                            break;
                    }
            }

            for(i=2; i<=l-m; i++)
            {
                for(j=0; j<=10; j++)
                {
                    vf[nff[i][j]]=vf[nff[i][j]]-nff1[i][j];
                    if(nff[i][j+1]==0)
                        break;
                }
            }

            for(i=0; i<q.size(); i++)
            {
                res=(res*mod_pow(q[i],vf[q[i]]))%n;
                vf[q[i]]=0;
            }
            vf[0]=0;
            q.clear();
        }
        printf("Case %lld: %lld\n",c,res+1);
        c++;
    }
    return 0;
}
