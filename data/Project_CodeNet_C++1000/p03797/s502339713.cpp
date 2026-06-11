#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n, m, ans;
    cin >> n >> m;
    if (n*2 <= m) {
        ans = n;
        ll tmp = m - n*2;
        ans += tmp/4;
    } else {
        ans = m/2;
    }
    cout << ans << endl;
    return 0;
}