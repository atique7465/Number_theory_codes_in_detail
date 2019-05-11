#include<bits/stdc++.h>
using namespace std;
vector<long long int>v,f,nf;
long long int np =1000010;
long long int status[1000011];
long long int mod = 1000000007;
long long int MOD = 1000000007;
long long int n,m,i,j,ans,sum,ck,tc,cas=1;

void prime()
{
    for( i = 2; i<= np; i++ )
        status[i] = 0;
    for( i = 3; i*i <= np; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= np; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(2);
    for( i = 3; i <= np; i += 2 )
    {
        if( status[i] == 0 )
            v.push_back(i);
    }
}
/* This function calculates (a^b)%MOD */
/*long long mod_pow(long long x, long long y)
{
	long long ans;
	ans = 1;
	while(y>0) {
		if(y & 1) {
			ans = (ans * x) % MOD;
		}
		x = (x * x) % MOD;
		y = y >> 1;
	}
	return ans;
}*/

/*long long int pow(long long int a, long long int b)
{
    long long int ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            ans=(ans*a);
            if(ans>MOD) ans%=MOD;
        }
        a = (a*a);
        if(a>MOD) a%=MOD;
        b /= 2;
    }
    return ans;
}*/

long long int pow(long long int N,long long int P)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		long long int ret=pow(N,P/2);
		return ((ret%mod)*(ret%mod))%mod;
	}
	else return ((N%mod)*(pow(N,P-1)%mod))%mod;
}
long long int modInverse(long long int a,long long int m)
{
    return pow(a,m-2);
}

int main()
{
    prime();
    scanf("%lld",&tc);
    while(cas<=tc)
    {
        ans=1;
        scanf("%lld",&n);
        scanf("%lld",&m);
        for(i=0; v[i]*v[i]<=n; i++)
        {
            ck=0;
            if(n%v[i]==0)
            {
                while(n%v[i]==0)
                {
                    n/=v[i];
                    ck++;
                }
                f.push_back(v[i]);
                nf.push_back(ck);
            }
        }
        if( n > 1 )
        {
            f.push_back(n);
            nf.push_back(1);
        }

        for(i=0; i<f.size(); i++)
        {
            long long int fv=f[i];
            long long int p=nf[i];
            /*ans = (ans * (mod_pow(fv, p * m + 1LL) - 1LL + mod)) % mod;
            ans = (ans * mod_pow(fv - 1LL, mod - 2)) % mod;*/
            ans = (ans * (pow(fv, p * m + 1LL) - 1LL + mod)) % mod;
            ans = (ans * modInverse(fv-1,mod) ) % mod;
            nf[i]=0;
        }
        printf("Case %lld: %lld\n",cas,ans);
        f.clear();
        nf.clear();
        cas++;
    }
    return 0;
}
