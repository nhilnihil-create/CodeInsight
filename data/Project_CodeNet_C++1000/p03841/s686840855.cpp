#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using pll = pair<ll,ll>;
using vll = vector<pll>;
#define ff first
#define ss second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)

int main() {
    int n; cin >> n;
    vll x(n);
    vl ans(n*n, 0);
    queue<pll> r, l;
    rep(i,n) {
        cin >> x[i].ff;
        x[i].ss = i+1;
        ans[x[i].ff-1] = i+1;
    }
    sort(x.begin(), x.end());
    rep(i,n) if (x[i].ss > 1) l.push(pll(x[i].ss, x[i].ss-1));
    per(i,n) if (x[i].ss < n) r.push(pll(x[i].ss, n-x[i].ss));
    auto f = [&](int i, queue<pll> &que) {
        if (que.empty()) return;
        if (ans[i] == 0) {
            ans[i] = que.front().ff; que.front().ss--;
            if (que.front().ss == 0) que.pop();
        }
    };
    rep(i,n*n) f(i,l);
    per(i,n*n) f(i,r);

    int pos = 1;
    vl cnts(n+1,0);
    rep(i,n) {
        while (pos < x[i].ff) cnts[ans[pos-1]]++, pos++;
        if (cnts[x[i].ss] < x[i].ss-1) {
            cout << "No" << endl;
            return 0;
        }
    }
    pos = n*n;
    cnts.assign(n+1,0);
    per(i,n) {
        while (x[i].ff < pos) cnts[ans[pos-1]]++, pos--;
        if (cnts[x[i].ss] < n-x[i].ss) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i,n*n) {
        cout << ans[i] << " \n"[i==n*n-1];
    }
    return 0;
}
