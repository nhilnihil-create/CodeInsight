#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        ans += y - x + 1;
    }
    cout << ans << endl;
}