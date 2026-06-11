#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else 
        return gcd(b, a%b);
}

int main() {
    int N, K;  cin >> N >> K;
    ll *A = new ll[N];
    ll M = 0;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        M = max(M, A[i]);
    }

    ll g = A[0];
    for (ll i = 1; i < N; i++)
        g = gcd(g, A[i]);

     if (M >= K && (M-K)%g == 0)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}