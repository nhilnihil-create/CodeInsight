#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;
typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int rev_mod(long long int num){
	long long int pow_num = MOD - 2;
	long long int mod_num = MOD;
	long long int pow_cur = num;
	long long int ret = 1;
	while(pow_num > 0){
		if(pow_num % 2 == 1){
			ret *= pow_cur;
			ret %= mod_num;
		}
		pow_cur *= pow_cur;
		pow_cur %= mod_num;
		pow_num /= 2;
	}
	return ret;
}

long long int DP[2][5200] = {};

int main(){
	int N, sz;
	cin >> N;
	string s;
	cin >> s;
	DP[0][0] = 1;
	for(int i = 0; i < N; i++){
		int pos = (i + 1) % 2, pre = i % 2;
		DP[pos][0] = (DP[pre][0] + DP[pre][1]) % MOD;
		for(int j = 1; j < 5100; j++){
			DP[pos][j] = (DP[pre][j - 1] * 2 + DP[pre][j + 1]) % MOD;
		}
	}
	long long int S = DP[N % 2][s.size()];
	for(int i = 0; i < s.size(); i++){
		S *= rev_mod(2);
		S %= MOD;
	}
	cout << S << endl;
  return 0;
}
