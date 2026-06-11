#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

long long f(ll a) {
    if (a == 2) return 1;
    else if (a == 4 || a == 6 || a == 9 || a == 11) return 2;
    else return 3;
}

int main() {
    ll x,y; cin >> x >> y;
    if (f(x) == f(y)) cout << "Yes" << endl;
    else cout << "No" << endl; 
    
}