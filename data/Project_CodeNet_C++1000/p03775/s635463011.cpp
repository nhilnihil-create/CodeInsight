#include <iostream>
#include <cmath>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;
using ll = long long;

ll f(ll x){
    ll xDigit=0;
    while(x){
        xDigit++;
        x /= 10;
    }
    return xDigit;
}

int main(){
    ll n;
    cin >> n;
    for(ll i=sqrt(n); i<=n; i--){
        if(n%i==0){
            int j = n/i;
            cout << f(j) << endl;
            return 0;
        }
    }

    return 0;
}
