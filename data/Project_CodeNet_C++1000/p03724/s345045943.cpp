#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, m;

int main(void){
    cin >> n >> m;
    vector<lli> v(n);
    rep(i, m){
        lli a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a]++;
        v[b]++;
    }
    bool ok = true;
    rep(i, n){
        if(v[i]%2 == 1) ok = false;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
