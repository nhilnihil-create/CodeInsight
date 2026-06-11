#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for(int i=0; i < n; ++i)
#define repe(i, n) for(int i=0; i <= n; ++i)
#define repr(i, n) for(int i=n-1; i > 0; --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define PI 3.14159265359
#define vi vector<int>
#define vl vector<ll>
using namespace std;
template <class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template <class T> bool chmin(T &a, const T &b) {if (b<a) {a = b; return 1;} return 0;}
template <class T> using V=vector<T>;
const int INF = 1e9;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;
bool isPrime(int x) {
    if (x<2) return 0;
    else if (x==2) return 1;
    if (x%2==0) return 0;
    for(int i=3; i*i<=x; i+=2) if(x%i==0) return 0;
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    int cnt = 0;
    rep(i,n) {
        if (a[i]%2==1) {
            cnt++;
        }
    }
    if (cnt%2==1) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}