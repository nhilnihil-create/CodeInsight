#include<iostream>
#include<bitset>
#include<algorithm>

using namespace std;

typedef long long ll;

int N, K;
ll A[5000 + 10];
bitset<5000 + 10> dpl, dpr;
int suml[5000 + 10][5000 + 10], sumr[5000 + 10][5000 + 10];
//[x, y]  -> suml[y] - suml[x - 1], sumr[x] - sumr[y - 1]

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	sort(A, A + N);
	
	dpl[0] = 1;
	for (int j = 0; j < K; j++) {
		suml[0][j + 1] = suml[0][j] + dpl[j];
	}
	for (int i = 0; i < N; i++) {
		if(A[i] <= K)dpl |= (dpl << A[i]);
		for (int j = 0; j < K; j++) {
			suml[i + 1][j + 1] = suml[i + 1][j] + dpl[j];
		}
	}

	dpr[0] = 1;
	for (int j = 0; j < K; j++) {
		sumr[N][j + 1] = sumr[N][j] + dpr[j];
	}
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] <= K)dpr |= (dpr << A[i]);
		for (int j = 0; j < K; j++) {
			sumr[i][j + 1] = sumr[i][j] + dpr[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (K - A[i] <= 0)continue;
		bool f = true;
		for (int j = 1; j < K; j++) {
			//左右二つの情報のどれをとっても、[K - A[i], K)にないならば答え
			if (i == 0) {
				if (sumr[i + 1][K] - sumr[i + 1][K - A[i]]) {
					f = false;
				}
				break;
			}
			else if ((suml[i][j + 1] - suml[i][j]) == 1) {
				
				if (j < K - A[i]) {
					if (sumr[i + 1][K - j] - sumr[i + 1][K - A[i] - j]) {
						f = false;
					}
				}
				else {
					f = false;
				}
			}
		}
		if (f)ans++;
	}
	cout << ans << endl;
	return 0;
}
