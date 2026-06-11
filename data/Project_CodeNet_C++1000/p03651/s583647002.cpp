#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int A[100010];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    int GCD = 0, mx = 0;
    for (int i = 0; i < N; ++i) {
        GCD = gcd(GCD, A[i]);
        mx = max(mx, A[i]);
    }

    if (mx < K) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    if (K % GCD == 0) {
        cout << "POSSIBLE\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
