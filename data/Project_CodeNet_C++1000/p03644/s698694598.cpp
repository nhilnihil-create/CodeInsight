#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }
        if (cnt > mx) {
            ans = i;
            mx = cnt;
        }
    }
    cout << ans << endl;
    return 0;
}