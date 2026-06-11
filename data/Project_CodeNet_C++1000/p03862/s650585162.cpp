#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, x;

int main(void){
    cin >> n >> x;
    vector<lli> a(n);
    rep(i, n) cin >> a[i];
    vector<lli> b = a;
    if(b[0] > x) b[0] = x;
    rep(i, n){
        if(i+1<n && b[i]+b[i+1]>x){
            lli d = b[i]+b[i+1]-x;
            b[i+1]-=d;
        }
    }
    lli ans = 0;
    rep(i, n){
        ans+=a[i]-b[i];
    }
    cout << ans << endl;
    return 0;
}
