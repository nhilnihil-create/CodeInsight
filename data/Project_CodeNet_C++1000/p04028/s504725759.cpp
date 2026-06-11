#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

const ll M = 1000000007;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k&1LL){
		ret *= x;
		ret %= M;
	}
	return ret;
}

int main(){
	int N;
	string s;
	cin >> N >> s;
	
	static ll dp[2][5005] = {};
	int t = 0, t_ = 1;
	dp[t][0] = 1;
	for(int i = 0 ; i < N ; i ++){
		dp[t_][0] = dp[t][0]+dp[t][1];
		while(dp[t_][0] >= M)dp[t_][0] -= M;
		for(int j = 1 ; j <= i+1 ; j ++){
			dp[t_][j] = dp[t][j-1]*2+dp[t][j+1];
			while(dp[t_][j] >= M)dp[t_][j] -= M;
		}
		swap(t,t_);
	}
	cout << (dp[t][s.size()]*modpow(2,(M-2)*s.size()))%M << endl;
}

