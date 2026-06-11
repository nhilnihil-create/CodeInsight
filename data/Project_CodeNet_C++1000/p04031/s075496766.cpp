#include<bits/stdc++.h>

using namespace std;
static const long long maxLL = (long long) 1 << 62;
int main(void) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &a: A) cin >> a;
    long long cost = maxLL;
    for (int x = -100; x <= 100; ++x) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (x - A[i]) * (x - A[i]);
        }
        cost = min(cost, sum);
    }
    cout << cost << endl;
}