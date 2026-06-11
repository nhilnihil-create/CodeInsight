#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, n) cin >> a[i];
    
    ll res = 22222222222222;
    
    rep(i, 1<<n){
        // 見る対象の家をk個未満として計算する場合はスキップ
        if(__builtin_popcount(i) != k) continue;
        
        ll max_h = 0;
        ll num = 0;
        
        rep(j, n){
            if(i>>j & 1){
                if(a[j] <= max_h){
                    ++max_h;
                    num += max_h - a[j];
                }else{
                    max_h = a[j];
                }
            }
            max_h = max(max_h, a[j]);
        }
        
        // cout << i << "," << num << endl;
        // cout << num << endl;
        res = min(num, res);
    }
    
    cout << res << endl;
    return 0;
}