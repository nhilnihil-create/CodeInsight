#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    ll now = 1;
    rep(i, N){
        ll t; cin >> t;
        ll g = __gcd(now, t);
        t /= g;
        now *= t;
    }

    cout << now << endl;


    return 0;
}