#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    if (*max_element(ALL(A)) < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int g = 0;
    for (int a : A) g = gcd(g, a);
    if (K % g == 0) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}