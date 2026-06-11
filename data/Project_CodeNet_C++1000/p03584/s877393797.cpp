#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
vector<int> A, B;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    LL ans = 0;
    ++K;
    while (K) {
        int KK = K-1;
        K &= KK;
        LL tmp = 0;
        for (int i = 0; i < N; ++i) {
            if ((KK|A[i]) == KK)  tmp += B[i];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
