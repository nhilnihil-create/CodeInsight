#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B && B == C)
        cout << 1;
    else if (A == B || B == C || C == A)
        cout << 2;
    else
        cout << 3;
}