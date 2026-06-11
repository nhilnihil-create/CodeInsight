/**
*    author:  souzai32
*    created: 06.08.2020 04:12:18
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    rep(i,n) cin >> a.at(i);
    rep(i,m) cin >> b.at(i);
    bool same;

    rep(i,n-m+1){
        rep(j,n-m+1){
            same=true;
            rep(k,m){
                rep(l,m){
                    if(b.at(k).at(l)!=a.at(i+k).at(j+l)) same=false;
                    if(!same) break;
                }
                if(!same) break;
            }
            if(same) break;
        }
        if(same) break;
    }

    if(same) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}