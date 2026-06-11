//
// Created by yjq on 2019/11/5.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define  int ll
const int maxn = 4010;
int a[maxn * 2], n, x;
ll s[maxn * 2];
bool vis[maxn * 2];

struct line {
    int num, l;

    bool operator<(const line &b) const {
        return num > b.num;
    }
};

priority_queue<line> q;

ll get_ans(int t) {
    while(!q.empty())q.pop();
    int ans = s[n] + t * x;
    if (t == 0)return ans;
    for (int i = n - t + 1; i <= n; ++i)q.push({a[i], i});
    for (int i = n + 1; i <= n + n; ++i) {
        while (!q.empty() && q.top().l < i - t)q.pop();
        ans -= max(0ll, a[i] - q.top().num);
        q.push({a[i], i});
    }
    return ans;
}

//int
main() {
    __;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n + n; ++i) {
        if (i > n)a[i] = a[i - n];
        s[i] = s[i - 1] + a[i];
    }
    ll ans = s[n];
    for (int y = 0; y < n; ++y) {
        ans = min(ans, get_ans(y));
    }
    cout << ans << endl;
    return 0;
}
