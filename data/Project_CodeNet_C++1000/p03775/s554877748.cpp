#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    int a, b;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            a = i;
            b = n / i;
        }
    }
    string A, B;
    A = to_string(a);
    B = to_string(b);
    cout << max(SZ(A), SZ(B)) << endl;
}