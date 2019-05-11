#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>v,a;
ll status[40000];
void prime(int N) {
    ll i, j, sqrtN;
    sqrtN = int( sqrt((double) N ));
    for( i = 3; i <= sqrtN; i += 2 ) {
        if( status[i] == 0 ) {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(2);
    int ck=1;
    for( i = 3; i <= N; i += 2 ) {
        if( status[i] == 0 ){
                v.push_back(i);
        }
    }
}

ll count(ll a[], ll m, ll n)
{
    ll odd = 0, even = 0;
    ll counter, i, j, p = 1;
    ll pow_set_size = (1 << n);
    for (counter = 1; counter < pow_set_size;
                                   counter++)
    {
        p = 1;
        for (j = 0; j < n; j++)
        {
            if (counter & (1 << j))
            {
                p *= a[j];
            }
        }
        if (__builtin_popcount(counter) & 1)
            odd += (m / p);
        else
            even += m / p;
    }
    return odd - even;
}

int main()
{
    ll n,i,j,res=0;
    scanf("%lld",&n);
    int lt=int(sqrt((double)n));
    prime(lt);
    for(i=2; i<=lt; i++)
    {
        ll k=n/i;
        ll sum;
        ll d=i;
        for(j=0; v[j]*v[j]<=i; j++)
        {
            if(d%v[j]==0)
            {
                while(d%v[j]==0)
                {
                    d/=v[j];
                }
                a.push_back(v[j]);
            }
        }
        if(d>1)
        {
            a.push_back(d);
        }
        ll arr[a.size()-1];
        for(ll z=0; z<a.size(); z++)
            arr[z]=a[z];
        ll ss = a.size();
        ll wa=count(arr, k, ss); ll wb=count(arr,i,ss);
        sum=k-wa-i+wb;
        res+=sum;
        a.clear();
    }
    printf("%lld",res);
    return 0;
}
