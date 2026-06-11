#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, A;
    cin >> N;
    map<int, int> mp;
    rep(i,N) {
        cin >> A;
        ++mp[A];
    }
    ll ans = 1;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i,2) pq.push(0);
    for (auto x : mp) {
        if (x.second >= 2) {
            if (x.first > pq.top()) {
                pq.pop();
                pq.push(x.first);
                if (x.second >= 4) {
                    if (x.first > pq.top()) {
                    pq.pop();
                    pq.push(x.first);
                    }
                }
            }
        }
    }
    rep(i,2) {
        ans *= pq.top();
        pq.pop();
    }
    cout << ans << endl;
}
