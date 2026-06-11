#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <climits>
#include <functional>
#include <numeric>

using namespace std;

#define alloc(type,n) (type*)calloc(sizeof(type),(n));
typedef long long lli;

#define N 100000
#define MOD 1000000007

lli n;
vector<lli> x;
stack<lli> s;
lli ans;

lli factrial(lli x){
	static lli dp[N];
	if(dp[x]) return dp[x];
	if(x == 0) 	return dp[x] = 1;
				return dp[x] = (factrial(x-1) * x) % MOD;
}

int main(){
	cin >> n;
	x = vector<lli>(n);
	for(int i = 0;i < n;i++) cin >> x[i];
	ans = 1;
	for(int i = 0;i < n;i++){
		if(x[i] < s.size()*2+1) ans = (ans*(s.size()+1))%MOD;
		else s.push(x[i]);
	}
	cout << (ans*factrial(s.size())) % MOD << endl;
	return 0;
}
