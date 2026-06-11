#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    ll w, a, b;
    cin >> w >> a >> b;

    if(a < b){
        if(a+w < b) cout << b - (a+w) << endl;
        else cout << 0 << endl;
    }
    else{
        if(b+w < a) cout << a - (b+w) << endl;
        else cout << 0 << endl;
    }
    return 0;
}