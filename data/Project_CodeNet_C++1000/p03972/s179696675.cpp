#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll W, H;
    cin >> W >> H;
    vector<ll> p(W), q(H);
    Rep (i, W) {
        cin >> p[i];
    }
    p.push_back(1e9);
    Rep (i, H) {
        cin >> q[i];
    }
    q.push_back(1e9);
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    ll ans = 0, edge = 0;
    ll xnow = 0, ynow = 0;

    Rep (i, W+H) {
        if (p[xnow] < q[ynow]) {
            ans += p[xnow] * (H+1-ynow);
            xnow++;
        } else {
            ans += q[ynow] * (W+1-xnow);
            ynow++;
        }
    }

    cout << ans << "\n";
}