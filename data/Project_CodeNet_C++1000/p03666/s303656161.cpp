#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    bool check = false;
    for (ll i = 0; i <= N-1; i++) {
        ll l = A - i * D + (N-1-i) * C;
        ll r = A - i * C + (N-1-i) * D;
        if (l <= B && B <= r) {
            check = true;
            break;
        }
    }
    if (check) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
