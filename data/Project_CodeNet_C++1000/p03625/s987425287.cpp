#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n; cin >> n;
    map<ll, ll, greater<ll>> m;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        m[a]++;
    }

    ll w = 0, h = 0;
    for(auto p : m){
        if(h > 0 && w > 0) break;
        if(p.second >= 4){
            if(h > 0){
                w = p.first;
                break;
            }else{
                cout << p.first * p.first << endl;
                return 0;
            }
        }else if(p.second >= 2){
            if(h == 0) h = p.first;
            else w = p.first;
        }
    }
    cout << w * h << endl;
}
