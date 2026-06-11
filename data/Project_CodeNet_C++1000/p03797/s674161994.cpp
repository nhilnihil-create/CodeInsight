#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n, m; cin >> n >> m;
    ll ans = 0;
    if(n >= m/2) ans = m/2;
    else {
        ans = n;
        m -= 2 * n;
        ans += m / 4;
    }
    cout << ans << endl;
}