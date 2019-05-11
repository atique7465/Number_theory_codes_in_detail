#include<bits/stdc++.h>
using namespace std;
int used[20],number[20],tp;
void permutation(int at, int n)
{
    int i;
    if(at==n+1)
    {
        tp++;
        for(i=1; i<=n; i++)
        {
            cout<<number[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(i=1; i<=n; i++)
    {
        if(!used[i])
        {
            used[i]=1;
            number[at]=i;
            permutation(at+1,n);
            used[i]=0;
        }
    }
}
int main()
{
    int n;cout<<"enter the number upto permutation: ";cin>>n;
    tp=0;
    permutation(1,n);
    cout<<"total number f purmutation= "<<tp;
    return 0;
}
