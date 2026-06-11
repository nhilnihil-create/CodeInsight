#include <iostream>
#include <vector>

using namespace std;

const long long INF = (1LL << 60);

int main(){
	int N;
	while(cin >> N){
		vector<int> A(N), sign(N);
		cin >> A[0];
		sign[0] = 1;
		for(int i=1;i<N;i++){
			char c;
			cin >> c >> A[i];
			sign[i] = (c == '+' ? 1 : -1);
		}
		long long dp[2][3];
		for(int i=0;i<3;i++) dp[0][i] = dp[1][i] = -INF;
		dp[0][0] = 0;
		long long m[3] = {1, -1, 1};
		for(int i=0;i<N;i++){
			long long* cur = dp[i%2];
			long long* next = dp[1-i%2];
			for(int j=0;j<3;j++) next[j] = -INF;
			for(int j=0;j<3;j++){
				for(int k=0;k<=j;k++){
					next[k] = max(next[k], cur[j] + m[k] * sign[i] * A[i]);
					if(sign[i] == -1 && k+1 <= 2){
						next[k+1] = max(next[k+1], cur[j] + m[k] * sign[i] * A[i]);
					}
				}
			}
		}
		long long res = 0;
		for(int i=0;i<3;i++) res = max(res, dp[N%2][i]);
		cout << res << endl;
	}
}

