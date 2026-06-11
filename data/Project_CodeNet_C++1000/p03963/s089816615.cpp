#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 
 
int main() {
    ll n ,k;
    cin >> n >> k;
    ll ans = k;
    rep(i,n-1){
        ans *=(k-1);
    }
    cout << ans << endl;

}