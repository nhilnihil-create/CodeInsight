#include<bits/stdc++.h>
using namespace std;
using ll = long long;
static const int INFTY = (1 << 21);
ll func(ll a, ll b){
    ll x = 0, y = 0;
    while(a > 0){
        a /= 10;
        x++;
    }
    while(b > 0){
        b /= 10;
        y++;
    }
    return max(x, y);
}
int main(){
    ll N;
    cin >> N;
    ll ans = INFTY;
    for(ll i = 1; i * i <= N; i++){
        if(N % i == 0){
            ans = min(ans, func(i, N / i));
        }
    }
    cout << ans << endl;
    return 0;
}