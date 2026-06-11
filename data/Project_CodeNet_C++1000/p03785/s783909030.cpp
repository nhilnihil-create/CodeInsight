#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    sort(t.begin(),t.end());
    int ans=0,cnt=0,w=t[0];
    rep(i,n) {
        if (t[i]-w>k || cnt+1>c) {
            ++ans;
            w=t[i];
            cnt=1;
        } else {
            ++cnt;
        }
    }
    if (cnt>0) ++ans;
    cout << ans << endl;

    
    return 0;   
}