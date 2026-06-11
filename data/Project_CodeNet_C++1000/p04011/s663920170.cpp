#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    if (N <= K)
        cout << X * N;
    else
        cout << X * K + Y * (N - K);
}