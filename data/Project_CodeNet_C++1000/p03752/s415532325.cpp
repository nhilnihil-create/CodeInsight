#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
int main() {
    int N,K; cin >> N >> K;
    vector<ll> a(N),b(N);
    for (int i=0;i<N;i++) cin >> a[i];
    ll res = 1e11;
    for (int bit=0;bit<(1<<N);bit++){
        // フラグ立っているところが見えるように.
        if(__builtin_popcount(bit) < K) continue;
        ll cost = 0, max_h = 0;
        for (int i=0;i<N;i++){
            if ((bit & (1<<i)) && (a[i]<= max_h)){
                cost += (max_h + 1) - a[i]; 
                max_h++;
            }
            chmax(max_h, a[i]);
        }
        chmin(res,cost);
    }
    cout << res << endl;
    return 0;
}
