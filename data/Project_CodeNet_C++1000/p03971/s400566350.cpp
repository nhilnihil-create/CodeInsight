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
    ll n, a, b; string s;
    cin >> n >> a >> b >> s;
    ll cnt_a = 0, cnt_b = 0;
    rep(i, n){
        // 国内学生の場合
        if(s[i] == 'a'){
            if(cnt_a+cnt_b < a+b){ cnt_a++; Yes(); }
            else No();
        }
        // 海外学生の場合
        else if(s[i] == 'b'){
            if(cnt_a+cnt_b < a+b && cnt_b < b){ cnt_b++; Yes(); }
            else No();
        }
        // どちらでもない場合
        else No();
    }
}