#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
int inf=100000000;
ll INF=5000000000000000000;
ll MOD=1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n){
        rep (j,n) cin >> a.at(i).at(j);
    }
    ll ans=0;
    rep(i,n){
        for (int j=i+1;j<n;j++){
            int t=0;
            rep(k,n){
                if (k==i || j==k) continue;
                if (a.at(i).at(j)>a.at(i).at(k)+a.at(k).at(j)){
                    cout << -1 << endl;return 0;
                }
                if (a.at(i).at(j)==a.at(i).at(k)+a.at(k).at(j)) t=1;
            }
            if (t==0) ans+=a.at(i).at(j);
        }
    }
    cout << ans << endl;
}
