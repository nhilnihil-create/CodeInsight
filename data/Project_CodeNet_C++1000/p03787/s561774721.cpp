#include <iostream>
#include <vector>
#define int long long
using namespace std;

int color[100000];
vector<int> G[100000];

bool dfs(int v){
	bool flag = true;
	for(int to : G[v]){
		if(color[to] != -1){
			if(color[to] == color[v]) flag = false;
			continue;
		}
		color[to] = (color[v] + 1) % 2;
		if(!dfs(to)) flag = false;
	}
	return flag;
}

signed main(){
	int n,m,one = 0,two = 0,point = 0;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b; a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 0;i < n;i++) color[i] = -1;
	for(int i = 0;i < n;i++){
		if(color[i] == -1){
			color[i] = 0;
			if(!G[i].size()) point++;
			else if(dfs(i)) two++;
			else one++;
		}
	}
	cout << one * (one + two * 2) + two * two * 2 + point * n * 2 - point * point << endl;
	return 0;
}