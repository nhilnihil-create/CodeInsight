#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    cin >> m;
    vector<P> drink(m);
    rep(i,m) cin >> drink[i].first >> drink[i].second;
    rep(i,m) {
        int ans = 0;
        rep(j,n){
            if((drink[i].first)==(j+1)) {ans+=drink[i].second; continue;}
            ans+=t[j];
        }
        cout << ans << endl;
    }
    return 0;
}