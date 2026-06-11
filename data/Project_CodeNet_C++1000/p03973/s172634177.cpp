#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, i, j;
    cin >> n;
    vector<ll> A(n);
    for(i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll ret = 0;
    ll now = 0;
    for(ll x : A) {
        if(x % (now+1) != 0){
            ret += x / (now+1);
        } else {
            ret += (x / (now+1)) - 1;
        }
        if(x == now + 1) {
            now = x;
        }
        if(now == 0) now = 1;
        //cout << now << endl;
    }
    cout << ret << endl;
    return 0;
}