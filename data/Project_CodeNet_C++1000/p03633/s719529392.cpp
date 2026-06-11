#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int main() {
    int n;
    cin >> n;
    vector<ll>t(n);
    rep(i,n) cin >> t[i];
    ll ans = t[0];
    rep(i,n-1) {
        ans = lcm(ans,t[i+1]);
    }
    cout << ans << endl;
}