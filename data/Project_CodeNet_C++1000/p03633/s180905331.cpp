#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

ll gcd(ll x, ll y) {
    ll r = y % x;
    if (r == 0) return x;
    else return gcd(r, x);
}

int main() {
    int N;
    cin >> N;
    vector<ll> T(N);
    Rep(i, N) {
        cin >> T[i];
        if (i) T[i] = T[i] / gcd(T[i], T[i - 1]) * T[i - 1];
    }
    cout << T[N - 1] << endl;
    return 0;
}