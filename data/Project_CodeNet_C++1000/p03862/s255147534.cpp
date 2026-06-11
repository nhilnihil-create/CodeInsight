#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n, x; cin >> n >> x;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll cnt = 0;
    for(int i = 0; i < n - 1; i++){
        ll sum = a[i] + a[i + 1];
        if(sum > x){
            ll tmp = sum - x;
            cnt += tmp;
            if(tmp <= a[i + 1]){
                a[i + 1] -= tmp;
            }else{
                tmp -= a[i + 1];
                a[i + 1] = 0;
                a[i] -= tmp;
            }
        }
    }
    cout << cnt << endl;

}
