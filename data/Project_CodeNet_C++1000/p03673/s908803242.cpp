#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<ll> X, Y;
    rep(i, n){
        ll a; cin >> a;
        if(i%2==0)X.push_back(a);
        else Y.push_back(a);
    }
    if(n%2==1){
        reverse(all(X));
        for(auto x: X)cout << x << " ";
        for(auto y: Y)cout << y << " ";
    }else{
        reverse(all(Y));
        for(auto y: Y)cout << y << " ";
        for(auto x: X)cout << x << " ";
    }
    cout << ln;
}
