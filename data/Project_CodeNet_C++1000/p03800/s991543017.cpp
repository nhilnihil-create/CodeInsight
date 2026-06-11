#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

const char a[] = "SW";

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    string s; cin >> s;

    for (int bits = 0; bits < 4; bits++) {
        string ans;
        ans.push_back(a[bits & 1]);
        ans.push_back(a[(bits >> 1) & 1]);
        for (int i = 1; i < n - 1; i++) {
            ans.push_back(a[(ans[i] == 'S') ^ (s[i] == 'x') ^ (ans[i - 1] == 'S')]);
        }
        if ((ans[n - 1] == 'S') ^ (s[n - 1] == 'x') ^ (ans[n - 2] == ans[0])) continue;
        if ((ans[0] == 'S') ^ (s[0] == 'x') ^ (ans[n - 1] == ans[1])) continue;
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
