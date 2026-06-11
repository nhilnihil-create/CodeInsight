#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,k,ans=0;
    cin>>n>>k;
    vector<int> l(n);
    rep(i,n) cin>>l[i];
    sort(l.begin(),l.end(),greater<int>());
    rep(i,k) ans+=l[i];
    cout<<ans<<endl;
}
