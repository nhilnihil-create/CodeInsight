#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main() {
    ll N; cin >> N;
    string u, l; cin >> u >> l;

    int k = 0;
    ll ans = 1;
    for (int i = 0; i < N; i++)
    {
        if(u[i]==l[i]){
            if(k==0) ans *= 3;
            else if(k==1) ans *= 1;
            else ans *= 2;
            ans %= mod;
            k = 2;  
        } else {
            i++;
            if(k==0) ans *= 6;
            else if(k==1) ans *= 3;
            else ans *= 2;
            ans %= mod;
            k = 1;
        }
    }
    cout << ans << endl;
}