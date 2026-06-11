#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

int main(){

    int W, H;
    cin >> W >> H;

    vector<pair<ll, int>> vec(W + H);
    rep(i, W){
        cin >> vec[i].first;
        vec[i].second = 1;
    }
    rep(i, H){
        cin >> vec[i + W].first;
        vec[i + W].second = -1;
    }
    sort(all(vec));

    ll vert = H + 1, side = W + 1;
    ll ans = 0;
    rep(i, W + H){
        if(vec[i].second == 1){
            ans += vec[i].first * vert;
            side--;
        } else {
            ans += vec[i].first * side;
            vert--;
        }
    }

    cout << ans << endl;
    return 0;

}