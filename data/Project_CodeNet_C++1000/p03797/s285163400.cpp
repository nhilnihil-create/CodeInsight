#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll S, C;
    cin >> S >> C;

    ll ans = 0;
    C -= S * 2;

    if(C<0){
        C += S * 2;
        ans = C / 2;
    }
    else{
        ans = S + C / 4;
    }

    cout << ans << endl;

    return 0;
}