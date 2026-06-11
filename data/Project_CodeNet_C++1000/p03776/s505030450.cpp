#include <bits/stdc++.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
struct combination{
    vector<vector<ll>> c;
    combination() : c(60,vector<ll>(60)){
        rep(i,0,60){
            rep(j,0,i+1){
                if(j==0 || j==i){
                    c[i][j] = 1ll;
                }
                else{
                    c[i][j] = (c[i-1][j-1]+c[i-1][j]);
                }
            }
        }
    }
 
    ll operator ()(ll n, ll k){
        return c[n][k];
    }
} comb;

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    double v[n];
    map<double, int, greater<double>> mp;
    rep (i, 0, n) {
        cin >> v[i];
        mp[v[i]]++;
    }

    int cnt = 0;
    double sum = 0;
    ll ans = 1;
    double ave = 0;
    for (auto p : mp) {
        if (cnt + p.second < a) {
            sum += p.second * p.first;
            cnt += p.second;
        } else if (a <= cnt + p.second) {
            if (cnt == 0) {
                ans=0;
                rep(k,a,min(b,p.second)+1) ans+=comb(p.second,k);
                ave = p.first;
            } else {
                int cnt2 = a - cnt;
                ans=comb(p.second,cnt2);
                ave = (sum + cnt2 * p.first) / a;
            }
            break;
        }
    }
    cout << fixed << setprecision (15) << ave << "\n" << ans << "\n";
}
