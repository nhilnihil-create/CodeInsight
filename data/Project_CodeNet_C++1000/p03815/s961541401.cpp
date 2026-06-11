#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ll x; cin >> x;
    ll r = x % 11;
    if(11 < x){
        if(r == 0) cout << x / 11 * 2 << endl;
        else if(r <= 6) cout << x / 11 * 2 + 1 << endl;
        else cout << x / 11 * 2 + 2 << endl;
    }else if(x <= 6){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
}

