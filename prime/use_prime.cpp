#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll N = 100000010;
ll status[100000010];
int main() {
    ll i, j, sqrtN;
   // for( i = 2; i <= N; i++ ) status[i] = 0;
    sqrtN = int( sqrt((double) N ));
    for( i = 3; i <= sqrtN; i += 2 ) {
        if( status[i] == 0 ) {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    printf("2 ");
    int ck=1;
    for( i = 3; i <= N; i += 2 ) {
        if( status[i] == 0 ){
            if(i*i<=1000000000000)
                printf("%lld ", i);
        }
    }
    return 0;
}
