#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
int calcBitLength(ll n) {
    ll x = n;
    ll ret = 0;
    while (x > 0) {
        ret++;
        x >>= 1;
    }
    return ret;
}
/* main */
int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];

    int L = calcBitLength(K);
    int upper = 1 << (L-1);

    ll mx = 0LL;
    for (int i = 0; i < N; i++) {
        if ((K | a[i]) == K) mx += b[i];
    }

    // ex)
    // K  = 101100
    // 候補
    // K0 = 011111
    // K[1] = 0 -> x
    // K2 = 100111
    // K3 = 101011
    // K[4] = 0 -> x
    // K[5] = 0 -> x
    int upperK = (1 << L) - 1;
    for (int l = 0; l < L; l++) {
        int d = 1 << (L-1 - l);
        if (K & d) {
            upperK -= d;
            ll sum = 0;
            for (int i = 0; i < N; i++) {
                if ((upperK | a[i]) == upperK) sum += b[i];
            }
            mx = max(mx, sum);
            upperK += d;
        }
        else upperK -= d;
    }

    cout << mx << '\n';
}
