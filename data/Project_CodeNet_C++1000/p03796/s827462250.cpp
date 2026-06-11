#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = pow(10, 9) + 7;

int main(){
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;
}