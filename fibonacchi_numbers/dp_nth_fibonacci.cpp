///Fibonacci Series using Dynamic Programming
///Time Complexity: O(n)
///Extra Space: O(n)
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll fib(ll n)
{
  /* Declare an array to store Fibonacci numbers. */
  ll f[n+2];   // 1 extra to handle case, n = 0
  ll i;

  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}

int main ()
{
   ll n;
  cin>>n;
  printf("%lld", fib(n));
  getchar();
  return 0;
}

