#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	cout << fixed << setprecision(15);
	int N, A, B;
	cin >> N >> A >> B;
	vector<long long> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	
	vector<vector<long long>> dp1(N+1, vector<long long>(B+1));
	vector<vector<long long>> dp2(N+1, vector<long long>(B+1));
	dp2[0][0] = 1;
	for (int i = 1; i <=N; i++) {
		for (int j = 0; j <= B; j++) {
			if (j == 0) {
				dp2[i][j] = 1;
				continue;
			}

			long long val_sel = dp1[i-1][j-1] + V[i-1];
			long long val_nosel = dp1[i-1][j];
			long long num_sel = dp2[i-1][j-1];
			long long num_nosel = dp2[i-1][j];
			if ((num_sel > 0) && (num_nosel > 0)) {
				if (val_sel > val_nosel) {
					dp1[i][j] = val_sel;
					dp2[i][j] = num_sel;
				}
				else if (val_sel < val_nosel) {
					dp1[i][j] = val_nosel;
					dp2[i][j] = num_nosel;;
				}
				else {
					dp1[i][j] = val_sel;
					dp2[i][j] = num_sel + num_nosel;;
				}
			}
			else if ((num_sel > 0) && (num_nosel == 0)) {
				dp1[i][j] = val_sel;
				dp2[i][j] = num_sel;
			}
			else if ((num_sel == 0) && (num_nosel > 0)) {
				dp1[i][j] = val_nosel;
				dp2[i][j] = num_nosel;
			}
			else {
				dp1[i][j] = 0;
				dp2[i][j] = 0;
			}
		}
	}

	long double ans_val = 0;
	long long ans_sel = 0;
	for (int i = A; i <= B; i++) {
		if ((long double)dp1[N][i]/i > ans_val) {
			ans_val = (long double)dp1[N][i]/i;
			ans_sel = dp2[N][i];
		}
		else if ((long double)dp1[N][i]/i == ans_val) {
			ans_sel += dp2[N][i];
		}
	}
	cout << ans_val << endl << ans_sel << endl;
}
