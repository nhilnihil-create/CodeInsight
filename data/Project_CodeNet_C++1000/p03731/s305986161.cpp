#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,T;
    ll ans=0;
    cin>>n>>T;
    vector<int> t(n);
    rep(i,n) {
        cin>>t[i];
    }
    int before=t[0];
    int end=before+T;
    for (int i=1; i<n; i++) {
        if (t[i]-t[i-1]<=T) {
            end=t[i]+T;
        }
        else {
            ans+=end-before;
            before=t[i];
            end=before+T;
        }
    }
    ans+=end-before;
    cout<<ans<<endl;
}
