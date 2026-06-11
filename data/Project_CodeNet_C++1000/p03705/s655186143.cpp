#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    if(a>b){
        cout << 0 << endl;
        return 0;
    }
    if(a==b){
        cout << 1 << endl;
        return 0;
    }
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    ll ans=1+(n-2)*(b-a);
    cout << ans << endl;
}