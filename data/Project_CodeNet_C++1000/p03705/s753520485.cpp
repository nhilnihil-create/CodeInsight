#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,a,b;
    cin >> n >> a >> b;
    
    if (a <= b){
        if (n == 1){
            if (a == b){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if (n == 2){
            cout << 1 << endl;
        }
        else{
            ll l = a + b*(n-1);
            ll s = a*(n-1) + b;
            cout << l-s+1 << endl;
        }
    }
    else{
        cout << 0 << endl;
    }
}