#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}
int main() {
    int N;
    cin >> N;
    vector<ll> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    ll ans = T[0];

    for (int i = 1; i < N; i++)
    {
        
        ans = lcm(ans, T[i]);
        
    }
    
    cout << ans << endl;   
    return 0;

}