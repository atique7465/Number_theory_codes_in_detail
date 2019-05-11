#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[2010][2010];
ll mod=1000000000;
void combination()//combination_value_by_pascal_table
{
    ll i,j;
    for(i=0; i<=2000; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j==0||j==i)
                arr[i][j]=1;
            else
            {
                arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%mod;
            }
        }
    }
}
int main()
{
    combination();
    ll i,j;
    for(i=0; i<=100; i++)
    {
        for(j=0; j<=i; j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;}
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll ans=arr[n+k-1][k];
        printf("%lld\n",ans);
        c++;
    }
    return 0;
}
