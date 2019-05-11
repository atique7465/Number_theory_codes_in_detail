#include<bits/stdc++.h>
#define ll long long int
using namespace std;

double sqrt(double n) {
    double low = 0.0;
    double high = (double)n+1;
    double mid;
    while ((high-low) > 0.00001) {
        mid = (low+high) / 2;
        if (mid*mid < n) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int main()
{
    cout<<sqrt(87232525452345345335345);
    return 0;
}
