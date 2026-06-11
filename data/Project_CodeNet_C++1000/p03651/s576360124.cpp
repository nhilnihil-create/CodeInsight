#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

ll gcd(ll a,ll b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n); inv(n, a);
    sort(a.begin(), a.end(), greater<int>());
    int g = gcd(a[0], a[1]);
    for(int i = 2; i < n; i++){
        g = gcd(g, a[i]);
    }
    if(k <= a[0] && k % g == 0){
        cout << "POSSIBLE" << endl;
    }else {
        cout << "IMPOSSIBLE" << endl;
    }
}
