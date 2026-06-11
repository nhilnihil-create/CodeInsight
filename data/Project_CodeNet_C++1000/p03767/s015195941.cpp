// 　　＿＿
// 　／　<＠ﾌ
//  ｜(ﾉﾉハ))
//  ﾉ从ﾟヮﾟ从
// 　ﾉ｜ｿﾉГ|つ author:hotarunx
// 〈_ﾉ^^^ヽ|
// 　~~tｧtｧ~
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(3*n);
    for (int i = 0; i < 3 * n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += a[2 * i + 1];
    }

    cout << ans << endl;
}
