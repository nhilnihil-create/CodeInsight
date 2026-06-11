#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e+9;

int main(){
    ll n;
    cin >> n;
    int ans = INF;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ans = min(ans, (int)to_string(n / i).size());
        }
    }
    cout << ans << endl;
    return 0;
}