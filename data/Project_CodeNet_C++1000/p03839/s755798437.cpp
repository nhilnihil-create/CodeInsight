#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
#include <array>
#include <iomanip>
#include <cassert>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    std::vector<long long> sums(n);
    std::vector<long long> pos(n);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sums[i] = x + (i > 0 ? sums[i - 1] : 0LL);
        pos[i] = max(x, 0LL) + (i > 0 ? pos[i - 1]: 0LL);
    }

    auto get_value = [&](std::vector<long long>& v, int l, int r) {
        if (l == 0) {
            return v[r];
        }
        return v[r] - v[l - 1];
    };

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        if (i >= k - 1) {
            auto pos_sum = get_value(pos, i - k + 1, i);
            auto sum_sum = get_value(sums, i - k + 1, i);

            answer = max(answer, pos.back() - pos_sum + max(sum_sum, 0LL));
        }
    }
    cout << answer << endl;
}
