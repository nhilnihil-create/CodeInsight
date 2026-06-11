#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long lowbit(long long i) {
    return i & -i;
}

long long get(vector<long long>& bit, long long index) {
    long long result = 0;
    while (index > 0) {
        result += bit[index];
        index -= lowbit(index);
    }
    return result;
}

void add(vector<long long>& bit, long long index, long long val) {
    while (index < bit.size()) {
        bit[index] += val;
        index += lowbit(index);
    }
}

int main() {
    long long n, k, result = 0;
    cin >> n >> k;
    vector<long long> bit(n + 2), a(n + 1), b(n + 1);
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1] - k;
        b[i] = a[i];
    }
    sort(begin(b), end(b));
    for (long long i = 0; i <= n; i++) {
        auto it = upper_bound(begin(b), end(b), a[i]);
        result += get(bit, distance(begin(b), it));
        add(bit, distance(begin(b), it), 1);
    }
    cout << result;
    return 0;
}
