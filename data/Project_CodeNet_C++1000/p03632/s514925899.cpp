#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b <= c) cout << 0 << endl;
    else if(d <= a) cout << 0 << endl;
    else if(a <= c){
        if(b <= d) cout << b - c << endl;
        else cout << d - c << endl;
    }
    else if(c <= a){
        if(b <= d) cout << b - a << endl;
        else cout << d - a << endl;
    }

    return 0;
}