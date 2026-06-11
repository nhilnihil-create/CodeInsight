#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

int main(){
    int n, w;
    cin >> n >> w;

    ll minw, val;
    cin >> minw >> val;
    vector<vector<ll>> v(4, vector<ll>(1, 0));
    v[0].push_back(val);

    rep(i, n-1){
        int we;
        cin >> we >> val;
        v[we - minw].push_back(val);
    }

    rep(i, 4) sort(rall(v[i]));

    ll ans = 0;

    rep(i, v[0].size()){
        rep(j, v[1].size()){
            rep(k, v[2].size()){
                rep(l, v[3].size()){
                    ll we = (minw)*i + (minw+1)*j + (minw+2)*k + (minw+3)*l;
                    if(we <= w){
                        ll tmp = 0;
                        rep(m, i) tmp += v[0][m];
                        rep(m, j) tmp += v[1][m];
                        rep(m, k) tmp += v[2][m];
                        rep(m, l) tmp += v[3][m];
                        ans = max(ans, tmp);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}