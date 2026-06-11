#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n,m; cin>>n>>m;
    vector <vector<int>> a(n,vector <int>(m));
    rep(i,n)rep(j,m) {cin>>a[i][j]; a[i][j]--;}
    vector <bool>  list(m, true);
    int ans = INF;
    for(int i=m;i>=1;i--){
        vector <int> cnt(m); 
        rep(j,n){
            rep(k,m){
                int spt = a[j][k];
                if(list[spt]) {cnt[spt]++; break;}
            }
        }
        auto iter = max_element(all(cnt));
        ans = min(ans, *iter);
        list[iter - cnt.begin()] = false;
    }
    cout<<ans<<endl;
}
