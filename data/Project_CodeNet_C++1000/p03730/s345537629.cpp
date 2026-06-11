#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b, c;
    cin >> a >> b >> c;

    bool ok = false;
    int t = a;
    for(int i = 0; i < b; i++){
        if(a%b == c) ok = true;
        a += t;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}