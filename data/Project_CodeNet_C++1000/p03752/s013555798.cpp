#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;

vector<vector<int>> enuCmb(int n, int k) {
    vector<vector<int>> res;
    if (n==0 || k==0 || n<k) {
      	return res;
    } else { 
		res=enuCmb(n-1,k);
		vector<vector<int>> res1=enuCmb(n-1,k-1);
		rep(i,res1.size()) {
			res1[i].push_back(n-1);
			res.push_back(res1[i]);
		}
		if (k==1) {
			vector<int> ins={n-1};
			res.push_back(ins);
		}
		return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<ll> a(n),ma(n);
    rep(i,n) {
        cin >> a[i];
        if (i>0) ma[i]=(a[i]>ma[i-1])?a[i]:ma[i-1];
        else ma[0]=a[0];
    }
    vector<vector<int>> enu=enuCmb(n-1,k-1);
    rep(i,enu.size()) {
        rep(j,k-1) ++enu[i][j];
    }
    ll ans=10e15;
	rep(i,enu.size()) {
        ll tans=0;
        vector<ll> b(n);
        copy(a.begin(),a.end(),b.begin());
		rep(j,k-1) {
            int now=enu[i][j];
            if (j==0) {
                if (b[now]<=b[0]) {
                    tans+=b[0]+1-b[now];
                    b[now]=b[0]+1; 
                }
            } else {
                int prev=enu[i][j-1];
                int l=(b[prev]>ma[now-1])?b[prev]:ma[now-1];
                if (b[now]<=l) {
                    tans+=l+1-b[now];
                    b[now]=l+1;
                }
            }
        }
        ans=(tans<ans)?tans:ans;
	}
    cout << ans << endl;
    return 0;
}