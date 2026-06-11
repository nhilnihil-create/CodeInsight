#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
static const int MAX_N = 5000;
static const int MAX_K = 5000;

int N, K;
int a[MAX_N];

bool C(int num){
	vector<int> a2;
	a2.push_back(0);
	for(int i = 0; i < N; i++){
		if(i == num) continue;
		a2.push_back(a[i]);
	}
	bool dp[MAX_N][MAX_K + 1];
	fill(dp[0], dp[N], false);
	dp[0][0] = true;
	for(int i = 1; i < N; i++){
		for(int j = 0; j <= K; j++){
			if(dp[i - 1][j]) dp[i][j] = true;
			if(j - a2[i] < 0) continue;
			if(dp[i - 1][j - a2[i]]) dp[i][j] = true;
		}
	}
	for(int i = max(K - a[num], 0); i < K; i++){
		if(dp[N - 1][i]) return true;
	}
	return false;
}

int main(){
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	int lb = -1, ub = N;
	for(; ub - lb > 1; ){
		int mid = (ub + lb) / 2;
		if(!C(mid)) lb = mid;
		else ub = mid;
	}
	cout << ub << endl;
	return 0;
}