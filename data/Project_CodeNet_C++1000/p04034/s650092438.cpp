#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, m; cin >> n >> m;

    // 何個の玉が入っているか。
    vi ball(n, 1);
    
    // 赤の玉が入っている可能性があるか。
    vector<bool> pos(n, false); pos[0] = true;
    
    rep(i, m){
        // 0-basedで入力
        ll x, y;
        cin >> x >> y;
        x--; y--;

        // ボールの数を増減
        ball[y]++, ball[x]--;

        // もし、移動元に赤の玉がある可能性があるなら
        // 移動先にも赤の玉がある可能性が生じる
        if(pos[x]) pos[y] = true;

        // 移動後、移動元の玉の数が0となったら赤の玉がある可能性は消滅する。
        if(!ball[x]) pos[x] = false;
    }
    // 赤の玉がある可能性のある箱を数え上げる
    ll ans = 0;
    rep(i, n) if(pos[i]) ans++;
    cout << ans << endl;
}