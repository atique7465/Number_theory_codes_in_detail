#include<bits/stdc++.h>
using namespace std;
vector<int>v,divisor;
int output[25];
int listsize;
void primefactorize(int n)
{
    int sqrtn=int(sqrt((double)n));
    listsize=0;
    int i;
    for(i=0; v[i]<=sqrtn; i++)
    {
        int ck=0;
        if(n%v[i]==0)
        {
            while(n%v[i]==0)
            {
                n/=v[i];
                output[listsize]=v[i];
                listsize++;
                ck++;
            }
            divisor.push_back(ck);
        }
    }
    if( n > 1 )
    {
        // n is greater than 1, so we are sure that this n is a prime
        output[listsize] = n; // added n (the prime) in the list
        listsize++;// increased the size of the list
        divisor.push_back(1);
    }
}

int main()
{
    int n,i,j,sqrtk,k,l;
    cin>>n;
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
    //for(i=0; i<v.size(); i++)
    // printf("%d ",v[i]);

    primefactorize(n);
    cout<<"prime factors are: "<<endl;
    for(i=0; i<listsize; i++)
    {
        printf("%d ",output[i]);
    }

    cout<<endl;

    int div_num=1;
    for(i=0; i<divisor.size(); i++)
    {
        div_num=div_num*(divisor[i]+1);
    }
    cout<<"number of divisors are: "<<endl<<div_num<<endl;



    return 0;
}
