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
	}
	sort(V.rbegin(), V.rend());

	pair<long long, long long>pans;
	long long anscount = 0;
	long long sum = 0;
	{
		for (int i = 0; i < A; ++i) {
			sum += V[i];
		}
		int count0 = 0;
		int count1 = 0;
		for (int i = 0; i < N; ++i) {
			if (V[A - 1] == V[i]) {
				count0++;
				if (i <= A - 1) {
					count1++;
				}
			}
		}
		long long anscountsub = C[count0][count1];
		pans = make_pair(sum, A);
		anscount = anscountsub;
	}
	{
		for (long long i = A + 1; i <= B; ++i) {
			sum += V[i - 1];
			int count0 = 0;
			int count1 = 0;
			for (int j = 0; j < N; ++j) {
				if (V[i - 1] == V[j]) {
					count0++;
					if (j <= i - 1) {
						count1++;
					}
				}
			}
			long long anscountsub = C[count0][count1];
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