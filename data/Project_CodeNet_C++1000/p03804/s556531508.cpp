#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,m;
    cin>>n>>m;
    vector<string> a(n),b(m);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    if (n>=m) {
        for (int i=0; i<=n-m; i++) {
            for (int j=0; j<=n-m; j++) {
                int count=0;
                rep(k,m) {
                    rep(l,m) {
                        if (a[i+k][j+l]==b[k][l]) {
                            count++;
                            //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                        }
                    }
                }
                if (count==m*m) {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
}
