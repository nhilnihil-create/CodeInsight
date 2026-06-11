#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
int main() {
    int N;
    cin >> N;
    i64 S = 0;
    vector<i64> s(N);
    for(int i = 0; i < N; i++) {
        cin >> s[i];
        S += s[i];
        if(i) s[i] += s[i - 1];
    }
    i64 ans = 1e16;
    for(int i = 0; i < N - 1; i++) {
        ans = min(ans, abs(S - 2 * s[i]));
    }
    cout << ans << endl;
    return 0;
}