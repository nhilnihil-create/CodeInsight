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
    ll h, w; cin >> h >> w;
    // 文字列群中の各文字の出現回数をカウント
    map<char, ll> cnt;
    rep(i, h){
        string s; cin >> s;
        ll n = s.size();
        rep(j, n) cnt[s[j]]++;
    }

    vi com(5, 0);
    for(auto &num: cnt){
        // 4個対がいくつつくれるか。
        com[4] += num.second/4;
        // 余りが0,1,2,3の数も覚えておく
        com[num.second%4]++;
    }
    // 3個のあまりは2個対と1個に分ける
    com[2] += com[3], com[1] += com[3];

    bool ans = false;
    // hもwも偶数の場合, h*w/4個の4個対が必要
    if(h%2 == 0 && w%2 == 0){
        com[4] == h*w/4 ? ans = true : false;
    }
    else{
        // hが偶数でwが奇数
        if(h%2 == 0 && w%2 != 0){
            ll req = h*(w-1)/4;
            if(com[4] >= req){
                com[4] -= req;
                com[2] += (com[4]*2);
                h/2 == com[2] ? ans = true : false;
            }
            else{
                ans = false;
            }
        }
        // hが奇数でwが偶数
        else if(h%2 != 0 && w%2 == 0){
            ll req = (h-1)*w/4;
            if(com[4] >= req){
                com[4] -= req;
                com[2] += (com[4]*2);
                w/2 == com[2] ? ans = true : false;
            }
            else{
                ans = false;
            }
        }
        // どっちも奇数
        else{
            ll req = (h-1)*(w-1)/4;
            if(com[4] >= req){
                com[4] -= req;
                com[2] += (com[4]*2);
                req = (h-1)/2 + (w-1)/2;
                req == com[2] && com[1] == 1 ? ans = true : false;
            }
            else{
                ans = false;
            }
        }
    }
    ans ? Yes() : No();
}