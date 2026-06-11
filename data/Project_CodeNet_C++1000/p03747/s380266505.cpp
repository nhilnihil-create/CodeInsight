#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
int main(void) {
    ll n, l,t,cnt = 0; cin >> n >> l>>t;
    vector<ll> x(n), w(n),dis(n);
    rep(i, n) cin >> x[i] >> w[i];
    rep(i, n) {
        if (w[i] ==1) {
            dis[i] = (x[i] + t) % l;
            cnt -= (t - (l - x[i]) + l) / l;
        }
        else {
            dis[i] = ((x[i] - t) % l + l) % l;
            cnt += (t - (x[i] + 1) + l) / l;
        }
    }
    cnt = (cnt % n + n) % n;
    sort(ALL(dis));
    vector<ll> ans(n);
    rep(i, n) ans[(i + cnt) % n] = dis[i];
    for (int i : ans) cout << i << endl;
}