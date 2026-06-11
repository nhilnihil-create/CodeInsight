#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,m;
    cin>>n;
    vector<int> t(n);
    rep(i,n) cin>>t[i];
    cin>>m;
    rep(i,m) {
        int p,x,ans=0;
        cin>>p>>x;
        p--;
        rep(j,n) {
            if (j==p) ans+=x;
            else ans+=t[j];
        } 
        cout<<ans<<endl;
    }
}
