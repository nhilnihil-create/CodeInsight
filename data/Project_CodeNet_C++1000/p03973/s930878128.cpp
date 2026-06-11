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
    itn n; cin>>n;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    int ans = 0;
    int p;
    rep(i,n){
        if(i==0){
            ans += a[i]-1;
            p = 2;
            continue;
        }
        ans += (a[i]-1)/p;
        if(p==a[i]) p++;
    }
    cout<<ans<<endl;
}
