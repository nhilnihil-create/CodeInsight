#include <iostream>
#define llint long long
#define sgn(x) (((x)%2)?-1:1)
#define inf 100000000000000000

using namespace std;

llint N;
llint A[100005];
char op[100005];
llint dp[100005][10];

int main(void)
{
	cin >> N;
	N--;
	
	cin >> A[0];
	for(int i = 1; i <= N; i++) cin >> op[i] >> A[i];
	
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= 2; j++){
			dp[i][j] = -inf;
		}
	}
	
	dp[0][0] = A[0];
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= 2; j++){
			if(dp[i][j] == -inf) continue;
			if(op[i+1] == '+'){
				dp[i+1][j] = max(dp[i+1][j], dp[i][j] + sgn(j)*A[i+1]);
				if(j > 0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + sgn(j)*A[i+1]);
			}
			else{
				dp[i+1][j] = max(dp[i+1][j], dp[i][j] + sgn(j+1)*A[i+1]);
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + sgn(j+1)*A[i+1]);
				if(j > 0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + sgn(j+1)*A[i+1]);
			}
		}
	}
	
	/*for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			if(dp[i][j] == -inf) cout << "-inf" << " ";
			else cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << dp[N][0] << endl;
	return 0;
}