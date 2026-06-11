#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            ll ans = (n-i)*j+(m-j)*i;
            if(ans==k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}