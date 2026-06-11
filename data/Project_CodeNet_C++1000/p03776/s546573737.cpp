// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 50;

long long vv[N];

long long ch(int n, int k) {
	return k == 0 ? 1 : ch(n - 1, k - 1) * n / k;
}

int main() {
	int n, a, b; cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> vv[i];
	sort(vv, vv + n, greater<>());
	long long sum = 0; int cnt = 0;
	long long sum_ = 0; int cnt_ = 1; long long ways = 0;
	for (int i = 0, j; i < n; i = j) {
		j = i + 1;
		while (j < n && vv[j] == vv[i])
			j++;
		int k = j - i;
		for (j = i; j < n && vv[j] == vv[i]; j++) {
			sum += vv[j];
			cnt++;
			if (a <= j + 1 && j + 1 <= b) {
				if (sum_ * cnt < sum * cnt_) {
					sum_ = sum;
					cnt_ = cnt;
					ways = ch(k, j - i + 1);
				} else if (sum_ * cnt == sum * cnt_)
					ways += ch(k, j - i + 1);
			}
		}
	}
	printf("%f\n%lld\n", (double) sum_ / cnt_, ways);
	return 0;
}
