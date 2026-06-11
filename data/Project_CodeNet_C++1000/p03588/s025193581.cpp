#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<ll, ll>;
using P3 = pair<int, P>;
using PP = pair<P, P>;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9) + 7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};


int main() {
    int n;
    cin >> n;
    vector<P> v(n); 
    for(int i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        v[i] = P(a,b);
    }
    sort(v.begin(), v.end());
    ll ans = v.back().first+v.back().second;
    cout << ans << endl;
    return 0;
}
