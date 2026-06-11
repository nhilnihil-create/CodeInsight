#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7LL;

    ll N;
    cin >> N;

    vector<ll> x(N);

    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        x[A]++;
    }

    if(N % 2) {
        if(x[0] != 1) {
            cout << 0 << endl;
            return 0;
        }

        for(int i = 2; i < N; i += 2) {
            if(x[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
        }

        cout << modpow(2LL, N / 2LL, mod) << endl;
    } else {
        for(int i = 1; i < N; i += 2) {
            if(x[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
        }

        cout << modpow(2LL, N / 2LL, mod) << endl;
    }
}