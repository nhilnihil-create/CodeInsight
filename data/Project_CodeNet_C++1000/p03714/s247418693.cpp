#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int64_t N;
    cin >> N;
    vector<int64_t> a(3*N);
    for(int64_t i=0; i<3*N; i++) {
        cin >> a[i];
    }

    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> l;
    int64_t lsum = 0;
    for(int64_t i=0; i<N; i++) {
        l.push(a[i]);
        lsum += a[i];
    }
    vector<int64_t> lsumv(3*N);
    lsumv[N-1] = lsum;
    for(int64_t i=N; i<2*N; i++) {
        if(a[i] > l.top()) {
            lsumv[i] = lsumv[i-1] - l.top() + a[i];
            l.pop();
            l.push(a[i]);
        } else {
            lsumv[i] = lsumv[i-1]; 
        }
    }

    priority_queue<int64_t, vector<int64_t>, less<int64_t>> r;
    int64_t rsum = 0;
    for(int64_t i=2*N; i<3*N; i++) {
        r.push(a[i]);
        rsum += a[i];
    }
    vector<int64_t> rsumv(3*N);
    rsumv[2*N] = rsum;
    for(int64_t i=2*N-1; i>=N; i--) {
        if(a[i] < r.top()) {
            rsumv[i] = rsumv[i+1] - r.top() + a[i];
            r.pop();
            r.push(a[i]);
        } else {
            rsumv[i] = rsumv[i+1]; 
        }
    }

    int64_t ans = INT64_MIN;
    for(int64_t K=N; K<=2*N; K++)  {
        ans = max(ans, lsumv[K-1] - rsumv[K]);
    }

    cout << ans << endl;
    return 0;
}
