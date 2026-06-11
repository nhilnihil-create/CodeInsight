#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll x; cin >> x;

    ll cnt = 0;
    if(11 <= x){
        cnt = x / 11 * 2;
        ll r = x % 11;
        if(r != 0){
            if(7 <= r) cnt += 2;
            else cnt++;
        }
    }else if(7 <= x){
        cnt += 2;
    }else{
        cnt += 1;
    }
    cout << cnt << endl;
}
