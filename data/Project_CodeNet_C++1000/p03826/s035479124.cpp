#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A * B > C * D)
        cout << A * B;
    else
        cout << C * D;
}