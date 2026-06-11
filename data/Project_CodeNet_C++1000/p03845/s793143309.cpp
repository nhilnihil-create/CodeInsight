#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    ll ans = 0;
    rep(i, n){
        cin >> t[i];
        ans += t[i];
    }
    int m;
    cin >> m;
    vector<int> p(m), x(m);
    rep(i, m){
        cin >> p[i] >> x[i];
    }

    rep(i, m){
        ll tmp = ans;
        tmp -= t[p[i]-1];
        tmp += x[i];
        cout << tmp << endl;
    }
}