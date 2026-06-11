#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    bool can = true;
    for(int i=0; i<=n-m; ++i){
        for(int j=0; j<=n-m; ++j){
            can = true;
            for(int k=0; k<m; ++k){
                string test = a[i+k].substr(j,m);
                string temp = b[k];
                if(test!=temp){
                    can = false;
                    break;
                }
            }
            if(can) break;
        }
        if(can) break;
    }

    if(can) cout("Yes");
    else cout("No");

    return 0;
}