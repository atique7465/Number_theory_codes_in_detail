#include<bits/stdc++.h>
using namespace std;
unsigned long long int phi[5000001];
int n=5000020;
int status[2500011];
int w=5000000;
vector<int>v;
int main()
{
    int t;
    for(t=0; t<5000001; t++)
    {
        phi[t]=t;
    }

    int i,j,sqrtn;
    sqrtn=int(sqrt((double)n));

    for(i=1; i<= sqrtn; i++)
        status[i]=0;

    for(i=3; i<=sqrtn; i+=2)
    {
        if(status[i>>1]==0)
        {
            for(j=i*i; j<=n; j+=2*i)
                status[j>>1]=1;
        }
    }
    v.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if(status[i>>1]==0)
            v.push_back(i);
    }

    int y,g,f,c=0;
    for( y=0; v[y]<=w; y++)
    {
        c++;
        for ( g = v[y]; g <= w; g += v[y] )
        {
            phi[g] *= (v[y] - 1);
            phi[g] /= v[y];
        }
    }
    for(f=1; f<=w; f++)
    {
        phi[f]=(phi[f]*phi[f])+phi[f-1];
    }

    int tc;
    scanf("%d",&tc);
    int h=1;
    while(h<=tc)
    {
        int a,b;
        unsigned long long int ans=0;
        scanf("%d %d",&a,&b);
        if(a<2){
            ans=phi[b];
            printf("Case %d: %llu\n",h,ans);
        }
        else
        {
            ans=phi[b]-phi[a-1];
            printf("Case %d: %llu\n",h,ans);
        }
        h++;
    }
    return 0;
}
