/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.20 03:41:51
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;cin >> n;
    int k;cin >> k;
    vector<ll> sum(n+1,0),best(n+1,0);
    for (int i = 0; i < n; i++) {
        int a;cin >> a;
        sum[i + 1] = sum[i] + a;
        best[i + 1] = best[i] + max(a,0);
    }
    ll ans = 0;
    //cerr << sum << endl;
    //cerr << best << endl;
    for (int i = 0; i < n-k+1; i++) {
        ans = max(ans,best[i] + best[n] - best[i+k] + max(0LL,sum[i+k] - sum[i]));
    }
    cout << ans << endl;
    return 0;
}