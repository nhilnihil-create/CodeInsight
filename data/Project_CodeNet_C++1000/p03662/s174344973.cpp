#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> a;

void dfs(int p, vector<int>& d, int c = 0){
	if(d[p] <= c) return;
	d[p] = c;
	for(int i = 0; i < a[p].size(); i++){
		dfs(a[p][i], d, c + 1);
	}
	return;
}

int main(){
	int n, ans = 0;
	cin >> n;
	a = vector<vector<int>>(n + 1);
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vector<int> d1(n + 1, n + 100), d2(n + 1, n + 100);
	dfs(1, d1);
	dfs(n, d2);
	int b = 0, w = 0;
	for(int i = 1; i <= n; i++){
		if(d1[i] <= d2[i]){
			b++;
		}else{
			w++;
		}
	}
	cout << (( b > w )? "Fennec" : "Snuke") << endl;
	return 0;
}