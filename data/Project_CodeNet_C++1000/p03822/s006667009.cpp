#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,a;
vector<vector<int>> u(100010);



int dfs(int n){
	int c = 0;
	if(u[n].size()==0) return 0;
	vector<int> dp;
	for(int i=0;i<u[n].size();i++){
		dp.push_back(dfs(u[n][i]));
	}
	sort(dp.begin(),dp.end());
	reverse(dp.begin(),dp.end());
	for(int i=0;i<dp.size();i++){
		c = max(c,dp[i]+i+1);
	}	
	return c;
}



int main(){
	cin >> N;
	for(int i=2;i<=N;i++){
		cin >> a;
		u[a].push_back(i);
	}
	cout << dfs(1) << endl;
}