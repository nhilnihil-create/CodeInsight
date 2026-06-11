/*
      author  : nishi5451
      created : 12.08.2020 23:31:04
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

ll INF = 1e9;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),b(n),c(m),d(m);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,m) cin >> c[i] >> d[i];
    
    rep(i,n){
        pair<ll,int> P(INF,-1);
        rep(j,m){
            ll dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(P.first > dist){
                P.first = dist;
                P.second = j;
            }
        }
        cout << P.second+1 << endl;
    }
    return 0;
}