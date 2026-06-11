#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> hash(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		a--;b--;
		if(a==0||a==n-1)
			hash[b].push_back(a);
		if(b==0||b==n-1)
			hash[a].push_back(b);
	}
	bool can=false;
	for(int i=1;i<n-1;i++){
		bool x = false;
		bool y = false;
		for(int j=0;j<hash[i].size();j++){
			if(hash[i][j]==0) x = true;
			if(hash[i][j]==n-1) y = true;
		}
		if(x&&y){
			can = true;
			break;
		}
	}
	if(can) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}
