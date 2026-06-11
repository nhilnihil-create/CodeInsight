#include<bits/stdc++.h>
using namespace std;
#define rep(i, V) for (int i = 0; i < V; i++)
#define _GLIBCXX_DEBUG

using ll = long long;

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a / g * b; //順を変えるとオーバーフロー
}

int main(){
    int N; 
    cin >> N;

    ll ans = 1LL;

    for (int i = 0; i < N; ++i){
        ll T; 
        cin >> T;
        ans = lcm(ans, T);
    }

    cout << ans << endl;
}
