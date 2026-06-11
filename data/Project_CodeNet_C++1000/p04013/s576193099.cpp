#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

long long dp[51][5005];
int x[50];

int main(){
	int N, A;
	cin >> N >> A;
	for(int i = 0 ; i < N; i++){
		cin >> x[i];
		x[i] -= A;
	}
	
	int gt = 2502;
	dp[0][gt] = 1;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < 5005 ; j++){
			dp[i+1][j] = dp[i][j];
		}
		for(int j = 0 ; j < 5005 ; j++){
			int t = j + x[i];
			if( t < 0 || t >= 5005 ) continue;
			dp[i+1][t] += dp[i][j];
		}
	}
	cout << dp[N][gt] - 1 << endl;
	
	
}
