#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool chmin (int &a, int b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	std::size_t n;
	std::cin >> n;
	std::vector<long long> a(n);
    std::vector<int> index(n);
    for (auto &e : a) std::cin >> e;

	std::iota(index.begin(), index.end(), 0);
	std::sort(index.begin(), index.end(), [&](int l, int r) { return (a[l] > a[r]); });

	int j = index[0], c = 0;
	long long s = 0;
	std::vector<long long> count(n, 0);
    for (std::size_t id = 0; id < n; id++) {
        const int &i = index[id];
        if (i < j) {
            const long long val = (s - a[i] * c);
            count[j] += val;
            s -= val;
            j = i;
        }
        c++;
        s += a[i];
        if (i == 0) {
            for (std::size_t k = id + 1; k < n; k++) {
                s += a[index[k]];
            }
            count[i] += s;
            break;
        }
    }

	for (auto ans : count) {
		std::cout << ans << '\n';
	}

	return 0;
}