#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

ll round_up(ll num, ll r) {
    ll up = 1 + (num-1) / r;
    return up*r;
}

int main() {
    int n;
    ll a, b, a2, b2;
    cin >> n >> a >> b;
    for(int i = 1; i < n; i++) {
        cin >> a2 >> b2;
        ll ab_gcd = __gcd(a2, b2); // avoid overflow
        ll a2_reduct = a2 / ab_gcd;
        ll b2_reduct = b2 / ab_gcd;
        if (a2 == b2) {
            a = b = max(a, b);
        } else if (a2 < b2) {
            a = round_up(a, a2);
            ll tmp_b = (a / a2_reduct) * b2_reduct;
            if (tmp_b >= b) {
                b = tmp_b;
            } else {
                b = round_up(b, b2);
                a = (b/ b2_reduct) * a2_reduct;
            }
        } else {
            b = round_up(b, b2);
            ll tmp_a = (b/ b2_reduct) * a2_reduct;
            if (tmp_a >= a) {
                a = tmp_a;
            } else {
                a = round_up(a, a2);
                b = (a / a2_reduct) * b2_reduct;
            }
        }
        //cout << a << " " << b << endl;
    }
    cout << (a+b) << endl;
    return 0;
}


