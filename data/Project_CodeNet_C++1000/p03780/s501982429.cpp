#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0, i_l = (int)n; i < i_l; i++)
#define loop(i, a, b) for (int i = a; i < (int)(b); i++)
 
const int MAX_COUNT = 5000;
ll N, K;
ll A[MAX_COUNT];
ll accum[MAX_COUNT];
set<ll> requiredNum;

ll searched[MAX_COUNT + 1][MAX_COUNT + 1];

 
void search(int from, ll value) {
    if (searched[from][value] > 0) {
        return;
    }
    searched[from][value] = 1;

    ll start = 0;
    if (from > 0) {
        start = accum[from - 1];
    }
    ll *left = lower_bound(accum + from, accum + N, value + start);
    if (left == accum + N) {
        return;
    }
    ll *right = upper_bound(accum + from, accum + N, value + start);
    int idx = left - accum;
    int nextIdx = right - accum + 1;
    for (int i = from; i <= idx && i < N; i++) {
        ll num = A[i];
        requiredNum.insert(num);
        search(nextIdx, min(num, value));
    }
}
int main() {
    cin >> N >> K;
    rep(i, N) cin >> A[i];
 
    //累積和
    sort(A, A + N, greater<ll>());
    accum[0] = A[0];
    loop(i, 1, N) {
        accum[i] = accum[i - 1] + A[i];
    }
    rep(i, N) {
        search(i, K);
    }
 
    //不要数をカウント
    int count = 0;
    rep(i, N) {
        if (requiredNum.find(A[i]) == requiredNum.end()) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}