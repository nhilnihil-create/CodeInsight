#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A <= C && B >= C)
        cout << "Yes";
    else
        cout << "No";
}