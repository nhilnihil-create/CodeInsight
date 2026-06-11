#include <iostream>
#include <vector>
using namespace std;

bool solve(long long N, const vector<long long> &a) {
    long long S = 0;
    for (int i = 0; i < N; ++i) S += a[i];
    if (S % (N * (N+1)/2) != 0) return false;
    long long num = S / (N * (N+1)/2);
    for (int i = 0; i < N; ++i) {
        long long b = a[(i+1)%N] - a[i] - num;
        if (b % N != 0 || b > 0) return false;
    }
    return true;
}

int main() {
    long long N; cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    if (solve(N, a)) cout << "YES" << endl;
    else cout << "NO" << endl;
}