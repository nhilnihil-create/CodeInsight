#include <cstdio>
using namespace std;

typedef long long int64;

struct Solution {
    int64 N, X;

    int64 F(int64 a, int64 b) {
        if (b % a == 0) return 2 * a * (b / a) - a;
        return 2 * a * (b / a) + F(b % a, a);
    }

    void Solve() {
        scanf("%lld%lld", &N, &X);
        printf("%lld\n", N + F(N - X, X));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
