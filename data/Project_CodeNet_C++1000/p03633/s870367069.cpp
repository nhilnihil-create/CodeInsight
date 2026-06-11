#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b) {
        if (a % b == 0) return b;
        else {
                return gcd(b, a % b);
        }
}
ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
}


int main()
{
        ll N; cin >> N;
        vector<ll> T(N, 0);
        for (int i = 0; i < N; ++i) {
                cin >> T[i];
        }
        if (N == 1) {
                cout << T[0] << endl;
                exit(0);
        }
        ll g = lcm(T[0], T[1]);
        for (int i = 2; i < N; ++i) {
                g = lcm(g, T[i]);
        }
        cout << g << endl;


}
