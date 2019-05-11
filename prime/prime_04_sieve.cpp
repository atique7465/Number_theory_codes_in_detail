#include<bits/stdc++.h>
using namespace std;
int n=500;
int status[251];
int main(){
    int i,j,sqrtn;
    sqrtn=int(sqrt((double)n));

         for(i=3; i<=sqrtn; i+=2){
            if(status[i>>1]==0)
            {
                for(j=i*i; j<=n; j+=2*i)
                    status[j>>1]=1;
            }
         }
        printf("2 ");
        for(i=3; i<=n; i+=2){
           if(status[i>>1]==0)
            printf("%d ",i);
}
return 0;
}
