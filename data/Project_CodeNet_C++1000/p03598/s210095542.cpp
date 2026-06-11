#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, K, ans = 0; cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (abs(0 - x) <= abs(K - x)) ans += 2 * x;
        else ans += 2 * abs(K - x);
    }
    printf("%d\n", ans);
}
