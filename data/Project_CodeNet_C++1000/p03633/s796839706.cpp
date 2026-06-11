#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll gcd(ll a, ll b){
    ll c = a;
    while(c != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int n;
    ll ans;
    cin >> n >> ans;
    for(int i = 1; i < n; i++){
        ll t;
        cin >> t;
        ll g = gcd(ans, t);
        ans = (ans / g) * (t / g) * g;

    }
    cout << ans << endl;
    return 0;
}