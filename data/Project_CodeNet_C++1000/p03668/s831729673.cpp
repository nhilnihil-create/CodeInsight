#include <iostream>
#include <vector>
using namespace std;

int N,x,y,visited[100010] = {0};
vector<vector<int>> v(100010);

int dfs(int n){
	visited[n] = 1;
	int g = 0;
	if(n!=1 && v[n].size()==1) return 0;
	for(int i=0;i<v[n].size();i++){
		int s = v[n][i];
		if(visited[s]==0){
			if((n==1 && v[n].size()==1) || n!=1 && v[n].size()==2) return dfs(s)+1;
			else{
				g ^= dfs(s)+1;
			}
		}
	}
	return g;
}

int main(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << (dfs(1)==0? "Bob":"Alice") << endl;
}