#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    bool ok = false;
    rep(i,n-m+1)rep(j,n-m+1){
        bool res = true;
        rep(x,m)rep(y,m){
            if(a[i+x][j+y] != b[x][y]){
                res = false;
                break;
            }
        }
        if(res){
            ok = true;
            break;
        }
    }
    cout << (ok?"Yes":"No") << endl;
    return 0;
}