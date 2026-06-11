#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> P(n,0);
	for(int i = 0; i < n; ++i)cin >> P[i];
	int wall = 1;
	long long ans = 0;
	ans += (long long)P[0] -1;
	wall++;
	
	for(int i = 1; i < n; ++i){
		if(P[i] < wall) continue;
		else if(P[i] == wall){
			wall++;
			continue;
		}
		else{
			ans += (long long)(P[i] - 1)/ wall;
		}
	}
	cout << ans << endl;
	return 0;
}
