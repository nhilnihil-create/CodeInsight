#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,k;
    cin>>n>>k;
    vi l(n);
    rep(i,n)cin>>l[i];
    sort(l.rbegin(), l.rend());
    int ans = 0;
    rep(i,k)ans+=l[i];
    
    cout << ans << endl;
    return 0;
}