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
    int n,k; cin>>n>>k;
    vector <pair<int,int>> data(n);
    rep(i,n){
        int a,b; cin>>a>>b;
        data[i] = {a,b};
    }
    sort(data.begin(),data.end());
    int ans1 = 0, maxbit=0;
    while((k>>maxbit)){
        maxbit++;
    }
    int ans = 0;
    
    rep(i,n) if(k == (k|data[i].F)) ans += data[i].S;
    
    rep(i, maxbit){
        int tmp = k, val = 0;
        if(!(tmp&(1LL<<i))) continue;
        tmp &= ~(1LL<<i); 
        rep(j,i) tmp |= (1LL<<j);
        rep(j,n) if(tmp==(tmp|data[j].F)) val += data[j].S;
        ans = max(ans, val);
    }
    cout<<ans<<endl;
}
