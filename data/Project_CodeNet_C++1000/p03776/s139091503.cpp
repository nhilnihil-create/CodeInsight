#include "bits/stdc++.h"
using namespace std;

long long C[51][51];
void comb_table(int N) {
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				C[i][j] = (long long)1;
			}
			else {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}
}

int main() {
	// 前処理
	int N, A, B;
	cin >> N >> A >> B;
	comb_table(N);
	vector<long long>V(N);
	for (int i = 0; i < N; ++i) {
		cin >> V[i];
		V[i] = -V[i];
	}
	sort(V.begin(), V.end());

	pair<long long, long long>pans;
	long long anscount = 0;
	long long sum = 0;
	{
		for (int i = 0; i < A; ++i) {
			sum += -1 * V[i];
		}
		pans = make_pair(sum, A);
		auto low1 = lower_bound(V.begin(), V.end(), V[A - 1]);
		auto up1 = upper_bound(V.begin(), V.end(), V[A - 1]);
		long long count = up1 - low1;
		long long first = low1 - V.begin();//V[frist]
		long long anscountsub = C[count][((A - 1) - (first)+1)];
		anscount = anscountsub;
	}
	{
		for (long long i = A + 1; i <= B; ++i) {
			sum += -1 * V[i - 1];
			auto low1 = lower_bound(V.begin(), V.end(), V[i - 1]);
			auto up1 = upper_bound(V.begin(), V.end(), V[i - 1]);
			long long count = up1 - low1;
			long long first = low1 - V.begin();//V[frist]
			long long anscountsub = C[count][((i - 1) - (first)+1)];
			if ((pans.first*i) < (sum*pans.second)) {
				pans = make_pair(sum, i);
				anscount = anscount;
			}
			else if ((pans.first*i) == (sum*pans.second)) {
				anscount += anscountsub;
			}
		}
	}
	long double dans = (long double)pans.first / (long double)pans.second;
	printf("%.10Lf\n", dans);
	cout << anscount << endl;
	return 0;

}