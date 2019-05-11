#include<bits/stdc++.h>
using namespace std;
int N = 50000;
bool isPrime( int i )
{
    for( int j = 2; j < i; j++ )
    {
       if( i % j == 0 ) // i is divisible by j, so i is not a prime
            return false;
    }
    // No integer less than i, divides i, so, i is a prime
    return true;
}

int main()
{
    for( int i = 2; i <= N; i++ )
    {
      if( isPrime(i) == true )
            printf("%d ", i);
    }
    return 0;
}
