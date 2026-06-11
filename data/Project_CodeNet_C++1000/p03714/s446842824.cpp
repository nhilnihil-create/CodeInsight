#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

const int MAX_N = 1e+5 + 10;
const ll INF = 1LL << 60;

ll a[3 * MAX_N], left_max[3 * MAX_N], right_max[3 * MAX_N];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < 3 * N; i++) {
        cin >> a[i];
    }
    ll left_score = 0, right_score = 0;
    priority_queue<ll> left_que, right_que;
    left_que.push(0);
    right_que.push(0);
    for (int i = 0; i < N; i++) {
        left_que.push(-a[i]);
        left_score += a[i];
    }
    for (int i = 3 * N - 1; i >= 2 * N; i--) {
        right_que.push(a[i]);
        right_score += a[i];
    }
    for (int i = N; i <= 2 * N; i++) {
        ll min_a = -left_que.top();
        left_que.pop();
        left_score -= min_a;
        left_max[i] = left_score;
        left_que.push(-a[i]);
        left_score += a[i];
    }
    right_max[2 * N] = right_score;
    for (int i = 2 * N - 1; i >= N; i--) {
        right_que.push(a[i]);
        right_score += a[i];
        ll max_a = right_que.top();
        right_que.pop();
        right_score -= max_a;
        right_max[i] = right_score;
    }
    // どこを境界にしたら最大スコアになるか全探索
    ll ans = -INF;
    for (int i = N; i <= 2 * N; i++) {
        ans = max(ans, left_max[i] - right_max[i]);
    }
    cout << ans << endl;
    return 0;
}