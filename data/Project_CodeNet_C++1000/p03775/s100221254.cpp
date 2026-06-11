#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    ll n, a = 0, b = 0;
    cin >> n;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            a = i;
            b = n / i;
        }
    }
    cout << SZ(to_string(max(a, b))) << "\n";
}