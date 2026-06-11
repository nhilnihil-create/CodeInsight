#include <iostream>
using namespace std;

long long ceiling(long long a, long long b) {
    if (a == 0) {
        return 0;
    }
    return (a - 1) / b + 1;
}

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long h[n], begin = 1, end = 0;
    for (int i = 0; cin >> h[i]; i++) {
        end = max(end, h[i]);
    }
    while (begin < end) {
        long long mid = (begin + end) / 2, count = 0;
        for (long long i = 0; i < n; i++) {
            if (h[i] - mid * b > 0) {
                count += max(ceiling(h[i] - mid * b, a - b), 0ll);
            }
        }
        if (count <= mid) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    cout << begin;
    return 0;
}
