#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    map<ll, ll, greater<ll>> m;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        m[a]++;
    }
    ll l1 = 0, l2 = 0;
    for(auto p : m){
        if(4 <= p.second && l1 == 0){
            l1 = p.first;
            l2 = p.first;
            break;
        }else if(2 <= p.second){
            if(l1 == 0){
                l1 = p.first;
            }else{
                l2 = p.first;
                break;
            }
        }
    }
    ll ans = l1 * l2;
    cout << ans << endl;
}
