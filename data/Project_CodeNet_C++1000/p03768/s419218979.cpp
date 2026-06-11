#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N, M;
	cin >> N >> M;
	vector<vector<int>> E(N); 
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	vector<vector<int>> dp(11, vector<int>(N, -1));
	int Q;
	cin >> Q;
	vector<int> c(Q);
	for (int i = 0; i < Q; i++){
		int v, d;
		cin >> v >> d >> c[i];
		v--;
		dp[d][v] = i;
	}
	for (int i = 10; i >= 1; i--){
		for (int j = 0; j < N; j++){
			dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
			for (int k : E[j]){
				dp[i - 1][k] = max(dp[i - 1][k], dp[i][j]);
			}
		}
	}
	for (int i = 0; i < N; i++){
		if (dp[0][i] == -1){
			cout << 0 << endl;
		} else {
			cout << c[dp[0][i]] << endl;
		}
	}
}