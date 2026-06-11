#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli k, t;

int main(void){
    cin >> k >> t;
    vector<lli> a(t);
    rep(i, t) cin >> a[i];
    sort(a.begin(), a.end());
    vector<lli> s(t+1);
    rep(i, t) s[i+1] = s[i]+a[i];
    lli x, y, d;
    d = 1e9;
    rep(i, t+1){
        if(abs(2*s[i]-s[t]) < d){
            d = abs(2*s[i]-s[t]);
            x = s[i];
            y = s[t]-s[i];
        }
    }
    cout << max(0LL, abs(x-y)-1) << endl;
    return 0;
}
