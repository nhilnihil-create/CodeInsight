#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
#define mod 1000000007
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	ll n,W;
	cin >> n >> W;
	int k = 0; 
	ll w[n];
	ll v[n];
	while(cin >> w[k] >> v[k])
		k++;
	unordered_map<ll, ll> dp;
	dp[0] = 0;
	ll res = 0;
	for(int i = 0; i < n; i++){
		auto dup = dp;
		for(auto el : dup){
			ll x = el.first + w[i];
			ll y = el.second + v[i];
			if(x <= W) res = max(res, dp[x] = max(dp[x], y));
		}
	}
	cout << res;
	return 0;
	
}

