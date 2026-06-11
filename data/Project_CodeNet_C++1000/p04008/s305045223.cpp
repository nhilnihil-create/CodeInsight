#include <iostream>
#include <vector>
using namespace std;

int N,K,A[100010],d[100010] = {0},ans = 0;
vector<vector<int>> v(100010);
int dfs(int n){
	for(int i=0;i<v[n].size();i++){
		dfs(v[n][i]);
		d[n] = max(d[n],d[v[n][i]]+1);
	}
	if(n!=1 && d[n]==K-1 && A[n]!=1){
		ans++;
		d[n] = -1;
	}
}

int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		if(i==1 && A[i]!=1) ans++;
		if(i!=1) v[A[i]].push_back(i);
	}
	dfs(1);
	cout << ans << endl;
}