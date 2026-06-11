#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;

int main(){
	int n,a;cin >> n >> a;
	vector<vector<ll>> dp(55,vector<ll>(2505,0));
	dp[0][0] = 1;
	rep(i,n) {
		int temp;cin >> temp;
		vector<vector<ll>> p(55,vector<ll>());
		p = dp;
		rep(j,i+1){
			for(int num = temp;num < 2505;num++){
				if(p[j][num-temp] != 0) {
					dp[j+1][num] += p[j][num-temp];
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ans += dp[i][i*a];
	}
	cout << ans << endl;

} 
 