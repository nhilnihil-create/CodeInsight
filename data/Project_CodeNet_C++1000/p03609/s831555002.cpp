#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int64_t X, t, zero = 0;
    cin >> X >> t;
    cout << max(X - t, zero) << endl;
}