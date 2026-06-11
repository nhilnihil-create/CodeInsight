#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

const ll L = 1000000007;

ll fnc(int x) {
    ll ret = 1;
    for (int i=1; i<=x; i++) {
        ret *= i;
        ret %= L;
    }
    return ret;
}

int main() {
    int m, n;
    cin >> m >> n;
    if (abs(m-n) > 1) cout << 0 << endl;
    else if (m == n) cout << (2*fnc(m)*fnc(n))%L << endl;
    else cout << (fnc(m)*fnc(n))%L << endl;
    return 0;
}