#include <bits/stdc++.h>

using namespace std;

long long N;

int findOfDigits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += 1;
        n /= 10;
    }
    return sum;
}

void solve() {
    int res = 12;
    for (long long i = 1; i <= (long long) pow(N, 0.5); ++i) {
        if (N % i == 0) {
            res = min(max(findOfDigits(i), findOfDigits(N / i)), res);
        }
    }
    printf("%d\n", res);
}

int main() {
    cin >> N;
    solve();
    return 0;
}