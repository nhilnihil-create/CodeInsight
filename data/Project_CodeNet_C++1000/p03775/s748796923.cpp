#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll b = 0;
    for(ll i = ll(pow(n, 0.5)); i > 0; i--){
        if(n%i == 0){
            b = n/i;
            break;
        }
    }
    int ans = 0;
    while(b > 0){
        b /= 10;
        ans++;
    }
    cout << ans << endl;
}