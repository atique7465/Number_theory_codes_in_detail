///We can optimize the space used in method 2 by storing the previous
///two numbers only because that is all we need to get
///the next Fibonacci number in series.
///Fibonacci Series using Space Optimized Method
///Time Complexity: O(n)
///Extra Space: O(1)
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll fib(ll n)
{
  ll a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}

int main ()
{
  ll n;
  cin>>n;
  printf("%lld", fib(n));
  getchar();
  return 0;
}
