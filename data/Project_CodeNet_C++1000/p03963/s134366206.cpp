#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ll n, k; cin >> n >> k;
    ll ans = k * pow(k-1, n-1);

    cout << ans << endl;
    return 0;
}