#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e+5+2;
long long array[N][3] = {0};

using P  = pair<char,int>;
long long solve(vector<P>& inputs) {
	int n = inputs.size();
	long long (*dp)[3] = array+1;
	dp[-1][1] = -1e+18;
	dp[-1][2] = -1e+18;

	for(int i = 0; i < n; i++) {
		auto pair = inputs[i];

		if(pair.first == '+'){
			dp[i][0] = max(dp[i-1][0] + pair.second, dp[i-1][1] + pair.second);
			dp[i][1] = max(dp[i-1][1] - pair.second, dp[i-1][2] + pair.second);
			dp[i][2] = dp[i-1][2] + pair.second;
		}else{
			dp[i][0] = max(dp[i-1][0] - pair.second,dp[i-1][1] - pair.second);
			dp[i][1] = max(dp[i-1][0] - pair.second, max(dp[i-1][1] - pair.second, dp[i-1][2] + pair.second));
			dp[i][2] = max(dp[i-1][1] + pair.second, dp[i-1][2] + pair.second);
		}
// 		cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	}

	return max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));
}

int main() {
	vector<P> inputs;

	int n;
	cin >> n;

	int first;
	cin >> first;
	inputs.push_back(P('+',first));

	for(int i = 0; i < n-1; i++) {
		char op;
		int m;
		cin >> op >> m;
		inputs.push_back(P(op,m));
	}

// 	for( auto pair: inputs)
// 		cout << pair.first << ":" << pair.second << endl;
	cout << solve(inputs) << endl;
}

