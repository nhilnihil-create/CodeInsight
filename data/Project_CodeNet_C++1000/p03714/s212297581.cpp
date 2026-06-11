#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
constexpr long INF = 1LL << 62;

int n;
long a[300010], L[300010], R[300010];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i < n * 3; ++i) cin >> a[i];

    // (sum of N from left) - (sum of N from right)
    
    // from left, maximize
    priority_queue<long, vector<long>, greater<long>> pq_max;
    for(int i=0; i < n * 3; ++i) {
        if(pq_max.size() < n) {
            L[i+1] = L[i] + a[i];
            pq_max.push(a[i]);
        } else {
            if(pq_max.top() < a[i]) {
                L[i+1] =  L[i] + a[i] - pq_max.top();
                pq_max.pop();
                pq_max.push(a[i]);
            } else {
                L[i+1] = L[i];
            }
        }
    }

    // from right, minimize
    priority_queue<long> pq_min;
    for(int i=n * 3 - 1; i >= 0; --i) {
        if(pq_min.size() < n) {
            R[i] = R[i+1] + a[i];
            pq_min.push(a[i]);
        } else {
            if(pq_min.top() > a[i]) {
                R[i] = R[i+1] + a[i] - pq_min.top();
                pq_min.pop();
                pq_min.push(a[i]);
            } else {
                R[i] = R[i+1];
            }
        }
    }

    long ans = -INF;
    for(int i=n; i <= n * 2; ++i) 
        ans = max(ans, L[i] - R[i]);

    cout << ans << endl;
    return 0;
}
