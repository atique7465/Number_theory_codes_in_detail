#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli M;

vector<vector<lli>> matmul(vector<vector<lli>> &A, vector<vector<lli>> &B)
{
    int n = A.size(), i, j, k;
    vector<vector<lli>> C(n, vector<lli>(n));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
    return C;
}

vector<vector<lli>> matpow(vector<vector<lli>> A, lli x)
{
    int n = A.size(), i;
    vector<vector<lli>> B(n, vector<lli>(n));
    for (i = 0; i < n; i++)
        B[i][i] = 1; /// Identity matrix
    while (x > 0)
    {
        if (x % 2)
            B = matmul(B, A);
        x /= 2;
        A = matmul(A, A);
    }
    return B;
}

int main(void)
{
    int i, j, k, kase = 0;
    lli A, N;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> A >> N >> M;

        /// setting x
        int x = 1;
        int tmp = A;
        while (tmp)
            x *= 10, tmp /= 10;

        /// setting the matrix T
        vector<vector<lli>> a(2, vector<lli>(2));
        a[0][0] = x % M;
        a[0][1] = 1;
        a[1][0] = 0;
        a[1][1] = 1;

        a = matpow(a, N - 1);
        cout << ((a[0][0] + a[0][1]) % M * A) % M << endl;
    }
    return 0;
}
