#include <bits/stdc++.h>
// #pragma GCC optimize("O3")

#define debug(var)  do{std::cerr << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cerr << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cerr << e << " "; } std::cerr << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ std::cerr << std::endl; for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n,m,k;

int main(){
    cin >> n >> m >> k;
    for(ll i = 0;i <= n;i++){
        for(ll j = 0;j <= m;j++){

            ll x = i*m + j*n - i*j*2;
            // debug(i);debug(j);debug(x);
            if(x == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
