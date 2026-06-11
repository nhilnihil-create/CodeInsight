#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> t(n, 0);
    rep1(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    ll ans = 1, lim = 1e10, cnt = 0;
    rep1(i, n){
        if (cnt<c){
            if (t[i]<=lim){
                cnt++;
                lim = min(lim, t[i]+k);
            } else{
                ans++;
                cnt = 1;
                lim = t[i] + k;
            }
        } else{
            ans++;
            cnt = 1;
            lim = t[i] + k;
        }
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}