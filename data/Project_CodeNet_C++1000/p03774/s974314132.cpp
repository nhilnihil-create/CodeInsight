#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > a, b;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        b.push_back({x, y});
    }
    
    for(ll i=0; i<n; ++i){
        pair<ll, ll> ans = {INT_MAX, 0};
        for(ll j=0; j<m; ++j){
            ans = min(ans, {abs(a[i].first-b[j].first) + abs(a[i].second-b[j].second), j});
        }
        cout << ans.second+1 << endl;
    }
}
