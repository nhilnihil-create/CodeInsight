#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m,ans=0;
    cin >> n >> m;
    vector<int> x(m),y(m);
    rep(i,m) cin >> x[i] >> y[i];
    vector<int> a(n+1,1);
    vector<bool> b(n+1,false);
    b[1]=true;
    rep(i,m){
        if(b[x[i]]){
            b[y[i]]=true;
        }
        --a[x[i]];
        ++a[y[i]];
        if(a[x[i]]==0){
            b[x[i]]=false;
        }
    }
    for(int i=1;i<=n;++i){
        if(b[i]) ++ans;
    }
    cout << ans << "\n";
    return 0;
}   