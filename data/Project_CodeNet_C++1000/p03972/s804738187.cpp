#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll w, h;
    cin >> w >> h;
    vector<pair<ll, int>> pq(h + w);
    for(int i = 0; i < h + w; i++) {
        cin >> pq[i].first;
        pq[i].second = i < w;
    }
    h++, w++;
    sort(all(pq));
    ll ans = 0;
    for(int i = 0; i < pq.size(); i++) {
        if(pq[i].second) {
            ans += pq[i].first * h;
            w--;
        } else {
            ans += pq[i].first * w;
            h--;
        }
    }
    cout << ans << endl;
}