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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> dq;
    bool is_reversed = false;

    for (auto &&i : a) {
        if (!is_reversed) {
            dq.emplace_back(i);
        } else {
            dq.emplace_front(i);
        }
        is_reversed = !is_reversed;
    }

    vector<int> ans;
    for (auto &&i : dq) {
        ans.emplace_back(i);
    }

    if (is_reversed) reverse(ans.begin(), ans.end());

    for (auto i = ans.begin(); i != prev(ans.end()); i++) {
        cout << *i << " ";
    }
    cout << *prev(ans.end()) << endl;
}
