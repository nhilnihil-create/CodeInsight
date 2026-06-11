#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    ll X = 0 , x = 0 , ans = 1000000000000000000;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        X += a[i];
    }
    for(int i = 0; i < n; i++){
        x += a[i];
        if(i + 1 < n){
           ans = min(ans , abs(X - 2 * x));
        }
    }
    cout << ans << endl;
}
