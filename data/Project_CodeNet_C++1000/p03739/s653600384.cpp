#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<ll> s(n+1);
    rep(i, n) {
        ll a; cin >> a;
        s[i+1] = s[i] + a;
    }
    ll cnt = 0;
    ll weight = 0;
    bool negative = true;
    for(int i=1;i<=n;i++) {
        ll num = s[i] + weight;
        if(!negative && num <= 0) {
            cnt += 1 - num;
            weight += 1 - num;
        }
        else if(negative && num >= 0) {
            cnt += num + 1;
            weight -= num + 1;
        }
        negative = !negative;
    }
    ll ans = cnt; cnt = 0;
    weight = 0;
    negative = false;
    for(int i=1;i<=n;i++) {
        ll num = s[i] + weight;
        if(!negative && num <= 0) {
            cnt += 1 - num;
            weight += 1 - num;
        }
        else if(negative && num >= 0) {
            cnt += num + 1;
            weight -= num + 1;
        }
        negative = !negative;
    }
    cout << min(ans, cnt);
}
