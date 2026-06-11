#include <bits/stdc++.h>
using namespace std;

//long long型(64bit整数)
typedef long long ll;

int main(){
    ll x;
    cin >> x;
    if(x % 11ll == 0){
        cout << x/11ll*2ll << endl;
    }else if(x % 11ll >=1  &&  x % 11ll <=6){
        cout << x/11ll*2ll + 1ll << endl;
    }else{
        cout << x/11ll*2ll + 2ll << endl;
    }
    return 0;
}