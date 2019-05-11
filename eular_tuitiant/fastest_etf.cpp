#include<bits/stdc++.h>
using namespace std;
vector<int> etf;
vector<bool > P;
void ETF(int n){
    etf.resize(n+1);
    P.resize(n+1,0);
    for(int i=1;i<=n;i++)
        etf[i]=i;
    for(int i=2;i<=n;i++){
        if(!P[i]){
            etf[i]-=(etf[i]/i);
            int j=2*i;
            while(j<=n){
                etf[j]-=(etf[j]/i);
                P[j]=1;
                j+=i;
            }
        }
    }
}
int main()
{
    ETF(10000000);
    for(int k=0; k<etf.size(); k++)
        cout<<etf[k]<<" ";
        cout<<etf.size();
    return 0;
}

