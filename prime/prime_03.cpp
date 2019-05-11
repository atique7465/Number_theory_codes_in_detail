#include<bits/stdc++.h>
using namespace std;
int N = 50000;
bool isPrime( int i )
{
    int sqrtI = int( sqrt( (double) i) );
    for( int j = 3; j <= sqrtI; j += 2 )   // j += 2 is given, condition (2)
    {
        if( i % j == 0 ) // i is divisible by j, so i is not a prime
            return false;
    }
    return true;
}
int main()
{
    printf("2 "); // 2 is the only even prime, so, print it
    for( int i = 3; i <= N; i += 2 )   // i += 2 is given here, condition (1)
    {
        if( isPrime(i) == true )
            printf("%d ", i);
    }
    return 0;
}
