#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <stack>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int N = (1 << 21); // 必要な数よりも大きい2^nよりも大きい数を入れるとよい
long long int BIT[(1 << 21) + 1];

void add(int a, long long int w){
	
	// a番目の要素にwを足す O(log N)
	
	for(int x = a; x <= N; x += x & -x){
		BIT[x] += w;
		BIT[x] %= MOD;
	}
}

long long int sum(int a){
	
	// 1からaまでの要素の合計を返す O(log N)
	
	long long int ret = 0;
	for(int x = a; x > 0; x -= x & -x){
		ret += BIT[x];
		ret %= MOD;
	}
	return ret;
}

void init(){
	for(int i = 0; i < N; i++){
		BIT[i] = 0;
	}
}

long long int DP[1100000] = {};

int main(){
	
	int n;
	cin >> n;
	
	init();
	
	DP[0] = DP[1] = DP[2] = 1;
	add(1, 1);
	add(2, 1);
	add(3, 1);
	
	
	for(int i = 3; i < n; i++){
		DP[i] = DP[i - 1];
		DP[i] += sum(i - 2);
		DP[i] %= MOD;
		add(i + 1, DP[i]);
	}
	
	long long int ans = 0;
	
	for(int i = 0; i < n - 1; i++){
		long long int p = (DP[i] * (n - 1)) % MOD;
		ans += p * (n - 1);
		ans += DP[i] * min(i + 2, n - 1);
		ans %= MOD;
	}
	
	ans += DP[n - 1] * n;
	ans %= MOD;
	
	cout << ans << endl;
	
	return 0;
}
