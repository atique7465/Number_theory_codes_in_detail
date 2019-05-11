///This another O(n) which relies on the fact that if we n times multiply the matrix M = {{1,1},{1,0}} to itself
///(in other words calculate power(M, n )), then we get the (n+1)th Fibonacci number as the element at row
///and column (0, 0) in the resultant matrix.
///Time Complexity: O(Logn)
///Extra Space: O(Logn) if we consider the function call stack size, otherwise O(1).
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void multiply(ll F[2][2], ll M[2][2]);

void power(ll F[2][2], ll n);

/* function that returns nth Fibonacci number */
ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}

/* Optimized version of power() in method 4 */
void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

/* Driver program to test above function */
int main()
{
  ll n;
  cin>>n;
  printf("%lld", fib(n));
  getchar();
  return 0;
}
