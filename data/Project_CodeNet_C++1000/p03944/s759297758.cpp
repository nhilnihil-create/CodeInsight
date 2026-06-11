#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int w,h,n,ans=0;
    cin>>w>>h>>n;
    vector<vector<bool>> r(w,vector<bool>(h,true));
    rep(i,n) {
        int x,y,a;
        cin>>x>>y>>a;
        if (a==1) {
            rep(j,x) {
                rep(k,h) {
                    r[j][k]=false;
                }
            }
        } else if (a==2) {
            for (int j=x; j<w; j++) {
                rep(k,h) {
                    r[j][k]=false;
                }
            }
        } else if (a==3) {
            rep(j,w) {
                rep(k,y) {
                    r[j][k]=false;
                }
            }
        } else {
            rep(j,w) {
                for (int k=y; k<h; k++) {
                    r[j][k]=false;
                }
            }
        }
    }
    rep(i,w) {
        rep(j,h) {
            if (r[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
}
