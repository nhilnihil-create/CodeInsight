#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    int n;
    cin >> n;
    ll t[n], a[n];
    rep(i, n) cin >> t[i] >> a[i];
    ll ans = 0;
    ll T = t[0], A = a[0];
    
    for (int i = 1; i < n; i++){
        ll ta = (A + a[i] - 1) / a[i];
        ll tt = (T + t[i] - 1) / t[i];
        A = a[i] * max(ta, tt);
        T = t[i] * max(ta, tt);
    }
    cout << A + T << endl;
    return 0;
}