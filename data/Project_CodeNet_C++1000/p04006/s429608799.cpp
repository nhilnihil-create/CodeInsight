#include <deque>
#include <iostream>
using namespace std;
int main() {
    int n, x; cin >> n >> x;
    int a[2*n]; for (int i = 0; i < n; i++) cin >> a[i], a[i+n] = a[i];
    long long ans = 1LL<<60;
    for (int k = 0; k < n; k++) {
        deque<pair<int, int> > deq;
        long long tmp = 0;
        for (int i = n-k; i < n; i++) {
            while (!deq.empty() && deq.back().second > a[i]) deq.pop_back();
            deq.push_back({i, a[i]});
        }
        for (int i = n; i < 2*n; i++) {
            while (!deq.empty() && deq.front().first < i-k) deq.pop_front();
            while (!deq.empty() && deq.back().second > a[i]) deq.pop_back();
            deq.push_back({i, a[i]});
            tmp += deq.front().second;
        }
        ans = min(ans, tmp + (long long)k * x);
    }
    cout << ans << endl;
}
