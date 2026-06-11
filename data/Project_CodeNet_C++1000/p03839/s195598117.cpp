#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    // ある連続するK個の部分以外は最適にできる
    int N, K;
    cin >> N >> K;
    vector<i64> A(N), B, SA(N + 1, 0), SB(N + 1, 0);
    for(auto &x : A) {
        cin >> x;
        B.push_back(max(x, i64(0)));
    }
    for(int i = 0; i < N; i++) {
        SA[i + 1] = A[i] + SA[i];
        SB[i + 1] = B[i] + SB[i];
    }
    i64 ans = -1;
    for(int i = K; i <= N; i++) {
        ans = max(ans, SB[i - K] + max(SA[i] - SA[i - K], i64(0)) + SB[N] - SB[i]);
    }
    cout << ans << endl;
    return 0;
}