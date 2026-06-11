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
    
    int k,s;
    ll ans=0;
    cin >> k >> s;
    rep(i,k+1){
        if(i>s) break;
        rep(j,k+1){
            if(i+j>s) break;
            if((s-i-j)<=k) ++ans;
        }
    }

    cout << ans << "\n";
    return 0;
}   