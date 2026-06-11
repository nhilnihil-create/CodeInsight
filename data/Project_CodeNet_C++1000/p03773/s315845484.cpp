#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9+7;




int main(){
    ll A, B; cin >> A >> B;
    ll ans = A+B;
    if(ans >= 24) ans-=24; 
    cout << ans << endl;
}