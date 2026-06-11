#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    long X, t;
    cin >> X >> t;
    cout << max(X - t, 0L) << endl;
}