#include<bits/stdc++.h>
using namespace std;
int arr[101];
int n=5000;
vector<int>v;
int main()
{
    int i,j,sqrtk,k,l;
    k=n/2;
    int status[(k/2)+1];
    sqrtk=int(sqrt((double)k));

    for(i=1; i<= k>>1; i++)
        status[i]=0;

    for(i=3; i<=sqrtk; i+=2)
    {
        if(status[i>>1]==0)
        {
            for(j=i*i; j<=k; j+=2*i)
                status[j>>1]=1;
        }
    }
    v.push_back(2);
    for(i=3; i<=k; i+=2)
    {
        if(status[i>>1]==0)
            v.push_back(i);
    }


    int w;
    int m;
    for(m=1; m<=100; m++)
    {
        int phi=m;
        w=m;
        int sqrtw=int(sqrt((double)w));
        for (int p = 0; v[p] <= sqrtw; p++)
        {
            if (w % v[p] == 0)
            {
                while (w % v[p] == 0)
                {
                    w /= v[p];
                }
                phi -= phi/v[p];
            }
        }
        if(w>1)
        {
            phi -= phi/w;
        }
        arr[m]=(phi*phi)+arr[m-1];
    }
    int tc;
    scanf("%d",&tc);
    int h=1;
    while(h<=tc)
    {
        int a,b,ans=0;
        scanf("%d %d",&a,&b);
        if(a==1||a==0)
            ans=arr[b];
        else
            ans=arr[b]-arr[a-1];

        printf("Case %d: %d",h,ans);
        h++;
    }

    return 0;
}
