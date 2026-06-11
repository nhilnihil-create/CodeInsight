#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    string s,t;
    cin >> s;
    cin >> t;
    int q;
    cin >> q;
    int a[q],b[q],c[q],d[q];
    rep(i,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
        c[i]--;
        d[i]--;
    }
    int n = s.size();
    int sums[n + 1] = {};
    rep(i,n){
        sums[i + 1] = s[i] == 'A' ? 1 : 2;
    }
    rep(i,n){
        sums[i + 1] += sums[i];
    }
    int m = t.size();
    int sumt[m + 1] = {};
    rep(i,m){
        sumt[i + 1] = t[i] == 'A' ? 1 : 2;
    }
    rep(i,m){
        sumt[i + 1] += sumt[i];
    }
    rep(i,q){
        if((sums[b[i] + 1] - sums[a[i]]) % 3 == (sumt[d[i] + 1] - sumt[c[i]]) % 3){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}