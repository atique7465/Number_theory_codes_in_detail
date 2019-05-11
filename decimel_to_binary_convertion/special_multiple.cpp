#include<bits/stdc++.h>
using namespace std;

long long int binary(long long int a)
{
    if(a==1) return 1;
    if(a%2==0)
        return 10*binary(a/2);
    else
        return 10*binary(a/2)+1;
}

int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        long long int n,b=9,i=1;
        scanf("%lld",&n);
        while(b%n!=0)
        {
            b=binary(i)*9;
            i++;
        }
        printf("%lld\n",b);
        c++;
    }
    return 0;
}
