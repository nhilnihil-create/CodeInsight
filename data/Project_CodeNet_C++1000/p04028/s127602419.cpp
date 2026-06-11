#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll memo[5050][5050];
bool done[5050][5050];

ll solve(int n, int k){
	if(done[n][k]){
		return memo[n][k];
	}
	done[n][k] = true;
	if(n<k){
		return memo[n][k] = 0ll;
	}else if(n==k){
		return memo[n][k] = 1ll;
	}
	add_mod(memo[n][k],solve(n-1,max(k-1,0)));
	add_mod(memo[n][k],(solve(n-1,k+1)*2)%MOD); 
	return memo[n][k];
}

int main(void){
	int n;
	string s;
	cin >> n;
	cin >> s;
	cout << solve(n,s.l_ength()) << endl;
	return 0;
}
