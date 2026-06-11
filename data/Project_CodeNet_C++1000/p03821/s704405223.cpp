#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    ll a, b;
    ll total = 0;
    ll ans = 0;
    ll x;
    vector<ll>A;
    vector<ll>B;

    cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    for (ll i = N-1; i >= 0; i--) {
        x = (A[i]+total) % B[i];
        total += (B[i]-x) % B[i];
        ans += (B[i]-x) % B[i];
    }
    cout << ans << endl;
}
