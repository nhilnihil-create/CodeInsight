#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    vector<ll> a(3*n);
    for(auto&x:a){
        cin >> x;
    }
    sort(a.begin(),a.end());
    ll ret = 0;
    ll now = 3*n-1;
    for(i=0;i<n;i++){
        ret += a[now-1];
        now-=2;
    }
    cout << ret << endl;
    return 0;
}