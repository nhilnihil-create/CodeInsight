#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    ll ans = 0;
    ll diff = B - A;
    for(ll i = 0; i < N; i++){
        ll j = N - 1 - i;
        ll mn = -D * i + C * j;
        ll mx = -C * i + D * j;
        if(mn <= diff && diff <= mx)ans = 1;
    }
    if(ans)cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
