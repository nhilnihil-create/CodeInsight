#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,T;
    cin >> n >> T;
    vector<int>t(n);
    rep(i,n) cin >> t[i];
    int ans = 0;
    rep(i,n-1) {
        int x = t[i+1] - t[i];
        ans += min(T,x);
    }
    ans += T;
    cout << ans << endl;
}