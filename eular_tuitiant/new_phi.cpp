#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll phi(ll n)
{
    ll ret = n;
    for(ll i = 2; i * i <= n; ++i)
        if(n % i == 0)
        {
            ret -= ret / i;
            cout<<"ret1="<<ret<<endl;
            while(n % i == 0) n /= i;
        }
    if(n > 1) {
        ret -= ret / n;
        cout<<"ret2="<<ret<<endl;
    }
    return ret;
}

int main()
{
    ll n;
    cin>>n;
    cout<<phi(n);
    return 0;
}
