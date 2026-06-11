#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll N,A,B;
    cin >> N >> A >> B;
    ll x[N+1];
    for(ll i = 1; i <= N; i ++){
        cin >> x[i];
    }

    ll ans = 0; 

    for(ll i = 1; i < N; i ++){
        if(B >= (x[i + 1] - x[i]) * A){
            ans += (x[i + 1] - x[i]) * A;
        }
        else{
            ans += B;
        }        
    }        

    cout << ans << endl;

return 0;
}