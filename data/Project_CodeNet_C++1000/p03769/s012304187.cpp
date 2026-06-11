/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

vector<int>solve(long long n){
	if(n == 1){
		vector<int>emp;
		return emp;
	}
	if(n % 2LL == 0){
		vector<int>ret = solve(n/2LL);
		ret.pb(ret.size() + 1);
		return ret;
	}
	vector<int>ret = solve(n-1LL);
	reverse(ret.begin(), ret.end());
	ret.pb(ret.size() + 1);
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	long long n;
	cin >> n;
	vector<int>ret = solve(n+1);
	cout << 2 * ret.size() << endl;
	for(auto u : ret) cout << u << ' ';
	repn(i, ret.size()) cout << i << ' ';
	cout << endl;
	return 0;
}

