#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    ll N, W; cin >> N >> W;
    vector<pair<ll, ll>> a, b, c, d;

    ll w1;
    for(int i=0; i<N; i++){
        ll w, v; cin >> w >> v;
        if(i == 0) w1 = w;

        if(w == w1) a.push_back({v, w});
        else if(w == w1+1) b.push_back({v, w});
        else if(w == w1+2) c.push_back({v, w});
        else d.push_back({v, w});
    }


    sort(a.begin(), a.end(), greater<pair<ll, ll>>());
    sort(b.begin(), b.end(), greater<pair<ll, ll>>());
    sort(c.begin(), c.end(), greater<pair<ll, ll>>());
    sort(d.begin(), d.end(), greater<pair<ll, ll>>());

    ll ans = 0LL;
    for(int i=0; i<=a.size(); i++){
        for(int j=0; j<=b.size(); j++){
            for(int k=0; k<=c.size(); k++){
                for(int l=0; l<=d.size(); l++){
                    ll weight = 0LL;
                    ll value = 0LL;

                    for(int m=0; m<i; m++) weight += a[m].second, value += a[m].first;
                    for(int m=0; m<j; m++) weight += b[m].second, value += b[m].first;
                    for(int m=0; m<k; m++) weight += c[m].second, value += c[m].first;
                    for(int m=0; m<l; m++) weight += d[m].second, value += d[m].first;
                    
                    if(weight <= W) ans = max(ans, value);

                }
            }
        }
    }

    cout << ans << endl;
}