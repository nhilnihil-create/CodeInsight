#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N,K; cin >> N >> K;
    vector<ll> a(N),b(N);
    for (int i=0;i<N;i++) cin >> a[i];
    ll res = 1e11;
    for (int bit=0;bit<(1<<N);bit++){
        b = a; 
        ll s = 0;
        ll max_h = 0;
        ll num_color = 0;
        for (int i=0;i<N;i++){
            if (!(bit & (1<<i))) {
                if (max_h < b[i]) num_color++;
            }
            else {
                if (max_h >= b[i]) {
                    s += max_h + 1 - b[i];
                    b[i] = max_h + 1;
                }
                num_color++;
            }
            max_h = max(max_h, b[i]);
        }
        if (num_color >= K) res = min(res,s);
    }
    cout << res << endl;
    return 0;
}