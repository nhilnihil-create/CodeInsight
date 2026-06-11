#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = max((b-a)*(n-2) + 1, 0ll);
    cout << ans << endl;
}