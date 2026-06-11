#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define int ll
signed main(){
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n-1);
    rep(i,n-1) s[i] = a[i] + a[i+1];
    int ans = 0;    
    rep(i,n-1) {
        if(s[i] > x) {
            if(s[i] - x <= a[i+1]) {
                int op = s[i] - x;
                ans+= op;
                s[i] -= op;
                s[i+1] -= op;
            } else {
                int op1 = a[i+1]; //a[i+1]から引く
                int op2 = (s[i]-x) - a[i+1]; //a[i]から引く
                ans+= op1 + op2;
                s[i] -= op1 + op2; 
                s[i+1] -= op1;
            }
        }
    }
    cout << ans << endl;
}
