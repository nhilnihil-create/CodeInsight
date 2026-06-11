#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int main() {
    int k, t;
    cin >> k >> t;
    priority_queue<P> pq;
    rep(i,t) {
        Int x;
        cin >> x;
        pq.push(P{x, i});
    }
    int ans = 0;
    Int pre_type = -1;
    P banned = {-1, -1};
    while (pq.size()) {
        P tp = pq.top();
        pq.pop();
        if (banned.first != -1) {
            pq.push(banned);
        }
        Int cake_cnt = tp.first;
        Int cake_type = tp.second;
        if (pre_type == cake_type) ans++;
        cake_cnt--;
        pre_type = cake_type;
        if (cake_cnt > 0) {
            if (pq.empty()) pq.push(P{cake_cnt, cake_type});
            else banned = P{cake_cnt, cake_type};
        }
        else {
            banned = P{-1, -1};
        }
    }
    cout << ans << endl;
}