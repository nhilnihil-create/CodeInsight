#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    ll n,m,ans;
    cin>>n>>m;
    if (n<m/2) {
        ans=n;
        m-=2*n;
        ans+=m/4;
    }
    else ans=m/2;
    cout<<ans<<endl;
}
