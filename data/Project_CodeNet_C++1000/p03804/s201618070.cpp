#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    bool ok = false;
    rep(i,n) {
        rep(j,n) {
            if(i+m-1 >= n || j+m-1 >= n) continue;
            bool match = true;
            rep(k,m){
                rep(l,m) {
                    if(a[i+k][j+l] != b[k][l]) match = false;

                }
            }
            if(match) ok = true;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}