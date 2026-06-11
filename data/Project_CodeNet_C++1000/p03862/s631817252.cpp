#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,x;
    cin >> n >> x;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    if(a[0] > x) {
        ans += a[0]-x;
        a[0] = x;
    }
    rep(i,n-1) {
        if(a[i]+a[i+1] > x) {
            int tmp = a[i]+a[i+1]-x;
            a[i+1] -= tmp;
            ans += tmp;
        }
    }
    cout << ans << endl;
}