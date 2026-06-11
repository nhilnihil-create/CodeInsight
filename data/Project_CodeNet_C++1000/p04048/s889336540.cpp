#include <bits/stdc++.h>

using namespace std;

long long  N, X, ans;

long long solve(long long a,long long b) {
    if(a == 0) return 0;
    if(b % a == 0) return 2 * a * (b / a) - a;
    return solve(b % a, a) + 2 * a * (b / a);
}

int main() {
    cin >> N >> X;
    cout << N + solve(min(X, N - X), max(X, N - X)) << endl;
    return 0;
}