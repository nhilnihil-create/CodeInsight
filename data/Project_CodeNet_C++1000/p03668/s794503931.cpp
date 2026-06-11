#include <bits/stdc++.h>
using namespace std;
int n, x, y, G[100005];
vector <int> v[100005];
int dfs(int x, int pa){
	for (int i=0; i<v[x].size(); i++)
		if(v[x][i]!=pa)
			G[x]^=(dfs(v[x][i], x)+1);
	if(!v[x].size())return 1;
	else return G[x];
}
int main(){ 
	cin>>n;n--;
	while(n--)cin>>x>>y, v[x].push_back(y), v[y].push_back(x);
	if(dfs(1, 1))cout<<"Alice";
	else cout<<"Bob";
}