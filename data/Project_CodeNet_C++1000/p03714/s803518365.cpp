#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using lint = long long;

int main() {
    int N;
    cin >> N;
    vector<lint> a(3*N);
    for (int i = 0; i < 3*N; i++) {
        cin >> a[i];
    }

    priority_queue<lint, vector<lint>, greater<lint>> lq;
    vector<lint> lsum(N + 1);
    lsum[0] = 0;
    for (int i = 0; i < N; i++) {
        lq.push(a[i]);
        lsum[0] += a[i];
    }

    for (int i = 0; i < N; i++) {
        if (a[N + i] > lq.top()) {
            lsum[i + 1] = lsum[i] - lq.top() + a[N + i];
            lq.pop();
            lq.push(a[N + i]);
        } else {
            lsum[i + 1] = lsum[i];
        }
    }

    priority_queue<lint> rq;
    vector<lint> rsum(N + 1);
    rsum[0] = 0;
    for (int i = 2*N; i < 3*N; i++) {
        rq.push(a[i]);
        rsum[0] += a[i];
    }

    for (int i = 0; i < N; i++) {
        if (a[2*N - i - 1] < rq.top()) {
            rsum[i + 1] = rsum[i] - rq.top() + a[2*N - i - 1];
            rq.pop();
            rq.push(a[2*N - i - 1]);
        } else {
            rsum[i + 1] = rsum[i];
        }
    }

    lint ans = lsum[0] - rsum[N];
    for (int i = 1; i <= N; i++) {
        if (ans < lsum[i] - rsum[N - i]) {
            ans = lsum[i] - rsum[N - i];
        }
    }

    cout << ans << endl;
    return 0;
}