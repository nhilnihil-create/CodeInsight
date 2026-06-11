#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll num_multi_4 = 0;
    ll num_multi_2 = 0; // 4の倍数を除く

    rep(i, n) {
        ll a;
        cin >> a;
        if (a % 4 == 0) num_multi_4++;
        else if (a % 2 == 0) num_multi_2++;
    }

    n -= max(num_multi_2 - 1, 0ll);
    ll limit = n / 2;

    cout << (num_multi_4 >= limit ? "Yes" : "No") << endl;

    return 0;
}
