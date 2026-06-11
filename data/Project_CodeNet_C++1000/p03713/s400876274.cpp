#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
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
    ll h, w, ans = INFLL; cin >> h >> w;

    // 割れる位置はh-1, w-1箇所
    // 極力(h*w)/3に近い値となるのが望ましい
    // すなわち、hまたはwが3の倍数なら答えは単純
    if(h%3==0 || w%3 == 0) ans = 0;

    // 初手を縦に割るケースと横に割るケースで分けて考える
    // 極力(h*w)/3に近い値となるように割る
    double  optValue = (h*w)/3.0;
    vi ve(1, 0), ho(1, 0);

    // 縦に割る位置を決める
    for(ll i=1; i<=w-1; i++){
        if(h*i >= optValue){
            ve[0] = i;
            if(i >=2) ve.push_back(i-1);
            break;
        }
    }

    // 横に割る位置を決める
    for(ll i=1; i<=h-1; i++){
        if(w*i >= optValue){
            ho[0] = i;
            if(i >=2) ho.push_back(i-1);
            break;
        }
    }

    // 最小値候補を計算
    for(auto p: ve){
        vi s(3);
        s[0] = h*p;
        ll tw = w-p;
        if(h%2 == 0 || tw%2 == 0) s[1] = s[2] = (h*tw)/2;
        else{
            ll tmp_s = h*tw;
            s[1] = max(h, tw)/2*min(h, tw);
            s[2] = tmp_s - s[1];
        }
        sort(all(s));
        chmin(ans, s[2]-s[0]);
    }

    for(auto p: ho){
        vi s(3);
        s[0] = w*p;
        ll th = h-p;
        if(th%2 == 0 || w%2 == 0) s[1] = s[2] = (th*w)/2;
        else{
            ll tmp_s = th*w;
            s[1] = max(th, w)/2*min(th, w);
            s[2] = tmp_s - s[1];
        }
        sort(all(s));
        chmin(ans, s[2]-s[0]);
    }
    cout << ans << endl;
}