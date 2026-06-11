#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    
    if (A[0] < K || (N == 1 && A[0] != K)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int p = A[0];
    for (int i = 1; i < N; i++) {
        p = gcd(A[i], p);
    }
    for (int i = 0; i < N; i++) {
        if (A[i]-K < 0) {
            break;
        }
        if ((A[i]-K) % p == 0) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

