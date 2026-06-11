#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<lli> a(n);
    vector<lli> s(n+1);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, n){
        s[i+1] = s[i]+a[i];
    }
    vector<lli> ans;
    rep(i, n){
        if(2*s[i] < a[i]){
            ans.clear();
        }
        ans.push_back(i);
    }
    cout << ans.size() << endl;
    return 0;
}
