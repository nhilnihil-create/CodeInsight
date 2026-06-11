#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 110;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            ll m = max(i, N/i);
            ll d = 0;
            while(m>0){
                d++;
                m = m / 10;
            }
            ans = min(ans, d);
        }
    }
    cout << ans << endl;

    return 0;
}