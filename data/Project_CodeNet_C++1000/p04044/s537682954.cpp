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

    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    sort(s.begin(), s.end());

    for (auto &&i : s) {
        cout << i;
    }
    cout << endl;
}
