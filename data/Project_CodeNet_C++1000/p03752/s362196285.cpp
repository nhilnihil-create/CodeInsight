#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define pii pair<int, int>
#define fi first
#define sc second
typedef long long ll;
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a_ori(n);
    rep(i, n)cin >> a_ori[i];
    
    ll ans = ll(1) << 40;
    rep(i, 1<<n){             //ビット全探索で、1になった建物を必ず見えるようにする。
        vector<int> a(a_ori);
        vector<int> list;
        rep(j, n)if(i & 1<<j)list.push_back(j);
        
        ll cost = 0;
        rep(j, list.size()){
            int targ = list[j];
            int max_h = 0;     // jより前の建物の中で一番高いやつの高さ。
            rep(k, targ)max_h = max(max_h, a[k]);
            if(max_h>=a[targ]){
                int diff = max_h - a[targ] + 1;
                a[targ] += diff;
                cost += diff;
            }
        }
        
        int max_h = 0;
        int cnt = 0;
        rep(j, n){
            if(a[j]>max_h){
                max_h = a[j];
                cnt++;
            }
        }
        
        if(cnt>=k && cost<ans)ans = cost;
    }
    
    
    cout << ans << endl;
}