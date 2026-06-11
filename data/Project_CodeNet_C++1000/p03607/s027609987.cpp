#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    ll n;
    cin >> n;
    vector<ll>a(n+1);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    int cnt = 0;
    int ans = 0;
    rep(i,n) {
        cnt++;
        if(a[i] != a[i+1]) {
            if(cnt%2 == 1) ans++;
            cnt = 0;
        }   
    }
    cout << ans << endl;
}