#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n; cin >> n;
    long long a, b; cin >> a >> b;
    vector<int> x(n);
    for (auto &xi: x) cin >> xi;
    min_heap<int> pq;
    for (int i = 1; i < n; i++) pq.emplace(x[i] - x[i - 1]);
    long long sum = 0;
    long long mi = b * (n - 1) + a * sum;
    for (int k = n - 2; k >= 0; k--) {
        sum += pq.top(); pq.pop();
        mi = min(mi, b * k + a * sum);
    }
    cout << mi << endl;
    return 0;
}
