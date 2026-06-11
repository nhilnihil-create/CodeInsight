#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &v, int now, int par = -1){
	int r = 0;
	for(auto n:v[now]) if(n != par){
		r ^= dfs(v, n, now) + 1;
	}
	return r;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	cout << (dfs(v, 0) ? "Alice" : "Bob") << endl;
}