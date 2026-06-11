#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    ans = k;
    ans *= pow(k-1,n-1);
    cout << ans;
}