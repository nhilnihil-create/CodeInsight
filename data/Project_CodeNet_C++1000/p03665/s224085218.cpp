#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


ll choose(int n, int k) {
    ll ret = 1;
    k = min(k, n-k);
    for(int i = n; i >= n-k+1; i--) {
        ret *= i;
    }
    for(int i = 1; i <= k; i++) {
        ret /= i;
    }
    return ret;
}

ll ipow(int n, int k) {
    ll ret = 1;
    for(int i = 0; i < k; i++) {
        ret *= n;
    }
    return ret;
}

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a[i] = b%2;
    }
    int all = count(a.begin(), a.end(), 1);
    ll ans = 0;
    int init = (p == 1);
    for(int i = init; i <= all; i+=2) {
        ans += choose(all, i) * ipow(2, n-all);
    }
    cout << ans << endl;

}