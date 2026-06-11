#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(51), b(51), c(51), d(51);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];

    int ans[51];
    for(int i=0; i<n; i++){
        ll tmp =400000000;
        int ids = 0;
        for(int j=0; j<m; j++){
            ll dis =0;
            dis = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(dis < tmp){
                tmp = dis; ids = j+1;
            }
        }
        ans[i] = ids;
        cout << ans[i] << endl;
    }
    return 0;
}