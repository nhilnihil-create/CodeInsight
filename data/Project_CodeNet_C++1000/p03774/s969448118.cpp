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


int main() {
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(n),c(m),d(m);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,m) cin >> c[i] >> d[i];
    rep(i,n) {
        int mi=INF;
        int ans;
        rep(j,m) {
            int dis=abs(a[i]-c[j])+abs(b[i]-d[j]);
            if (dis<mi) {
                mi=dis;
                ans=j;
            }
        }
        cout << ans+1 << endl;
    }
    

    return 0;   
}
