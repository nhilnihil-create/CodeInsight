#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll a, ll b) {
    if (a > b) swap(a, b);
    if (b % a == 0) {
        return (b/a)*a*2-a;
    }
    return (b/a)*a*2+f(b%a, a);
}
int main () {
    ll N, X;
    cin >> N >> X;
    if (X+X == N) {
        cout << N/2*3 << endl;
        return 0;
    }
    cout << N+f(X, N-X) << endl;
}