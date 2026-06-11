// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int aa[N + 1], ii[N + 1];
long long kk[N + 1];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> aa[i];
		ii[i] = i;
	}
	sort(ii, ii + n + 1, [] (int i, int j) { return aa[i] > aa[j]; });
	for (int h = 0, h_, i = n, i_; h < n; h = h_) {
		int a = aa[ii[h]];
		h_ = h;
		while (aa[i_ = ii[h_]] == a) {
			i = min(i, i_);
			h_++;
		}
		int b = aa[ii[h_]];
		kk[i] += (long long) (a - b) * h_;
	}
	for (int i = 1; i <= n; i++)
		cout << kk[i] << '\n';
	return 0;
}
