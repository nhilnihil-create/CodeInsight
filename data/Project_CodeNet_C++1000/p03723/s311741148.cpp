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
    ll a, b, c; cin >> a >> b >> c;
    if(a%2 == 1 || b%2 == 1 || c%2 == 1){
        cout << 0 << endl;
    }
    else if(a == b && b == c && c == a){
        cout << -1 << endl;
    }
    else{
        ll cnt = 0;
        while(a%2 == 0 && b%2 == 0 && c%2 == 0){
            cnt++;
            ll ta = (b+c)/2;
            ll tb = (a+c)/2;
            ll tc = (a+b)/2;
            a = ta, b = tb, c = tc;
        }
        cout << cnt << endl;
    }
}