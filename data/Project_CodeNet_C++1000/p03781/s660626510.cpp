#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll x;
    cin >> x;
    ll ans = 0;
    ll dist = 0;
    while(dist < x) {
        ans++;
        dist += ans;
    }
    cout << ans << endl;
}