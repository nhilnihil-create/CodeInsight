#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = (a * b)/gcd(a,b);
    return ret;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, 0, N) cin >> a[i];
    ll g = a[0];
    rep(i, 1, N) g = gcd(g, a[i]);
    if(K % g != 0 || *max_element(a.begin(), a.end()) < K) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
    return 0;
}