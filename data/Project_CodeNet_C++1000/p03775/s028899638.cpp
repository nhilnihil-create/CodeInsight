#include <bits/stdc++.h>
using namespace std;

// const long long int MOD = 1000000007;
const int MOD = 1000000007;

long long int F(long long int A, long long int B) {
    long long int C = max(A,B), ans = 0;
    while (C/10 > 0) {
        ans++;
        C /= 10;
    }
    ans++;
    return ans;
}

int main() {
    long long int N,ans = 11;
    cin >> N;
    for (long long int i = 1; i <= sqrt(N); i++) {
        if (N%i != 0) {
            continue;
        }
        ans = min(ans, F(i, N/i));
    }
    cout << ans << endl;
}