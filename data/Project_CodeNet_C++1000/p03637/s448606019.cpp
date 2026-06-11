#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n, odd = 0, evendiv = 0, even = 0;
    cin >> n;
    for(ll i = 0; i < n; ++i){
        ll tmp; cin >> tmp;
        if(tmp % 2 != 0)odd++;
        else if(tmp % 4 == 0)evendiv++;
        else even++;
    }
    if(even == 0){
        if(evendiv >= odd - 1){
            cout << "Yes";
        }else cout << "No";
    }
    else if(evendiv >= odd){
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}
