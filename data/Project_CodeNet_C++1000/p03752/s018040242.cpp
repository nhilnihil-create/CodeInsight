#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    auto f = [&](auto &&f, int i, int h, int64_t cost, int k) -> int64_t {
        if(i == N) return k == K ? cost : 1LL << 60;
        int nh = A[i] > h ? A[i] : h + 1;
        int64_t ncost = A[i] > h ? cost : cost - A[i] + h + 1;
        return min(f(f, i + 1, nh, ncost, k + 1), f(f, i + 1, max(h, A[i]), cost, k));
    };
    cout << f(f, 1, A[0], 0, 1) << '\n';
    return 0;
}
