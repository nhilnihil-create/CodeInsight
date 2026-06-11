#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int A, B, X;
    cin >> A >> B >> X;

    cout << (B / X + 1) - (A ? (A - 1) / X + 1 : 0) << endl;
    return 0;
}
