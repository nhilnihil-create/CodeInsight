#include <iostream>
#include <vector>
using namespace std;
vector<int> G[100010];
int dfs(int s,int p){
	int res = 0;
	for(int v:G[s]){
		if(v!=p){
			res ^= dfs(v,s);
		}
	}
	res++;
	return res;
}

int main(){
	int i,n;
	cin >> n;
	for(i=0;i<n-1;i++){
		int a,b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	if(dfs(0,-1)==1){
		cout << "Bob" << endl;
	}else{
		cout << "Alice" << endl;
	}
}