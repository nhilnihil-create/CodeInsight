#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    ll ans=0;
    if(n*2>=m){
        ans=m/2;
        cout << ans << endl;
        return 0;
    }
    ans+=n;
    m-=n*2;
    ans+=m/4;
    cout << ans << endl;
}