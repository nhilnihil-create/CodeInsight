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
    string s, t;
    cin >> s >> t;

    for (int i = n; i >= 0; i--) {
        const string u = s + t.substr(i, n - i);
        const string utail = u.substr(u.size() - n, n);

        if (utail == t) {
            cout << u.size() << endl;
            return 0;
        }
    }
}
