#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 100005;
const int mod = 998244353;

int n, m, x;
vector<int> v[MAXN];

int solve(vector<int> x, vector<int> y){
	if(x.size() > y.size()) swap(x, y);
	int ret = 0, reu = 0;
	for(int i=0; i+1<x.size(); i++){
		if(x[i] == x[i+1]){
			ret++;
			i++;
		}
	}
	for(int i=0; i+1<y.size(); i++){
		if(y[i] == y[i+1]){
			reu++;
			i++;
		}
	}
	int dap = x.size() * 2;
	dap += 2 * min(reu, (int)(y.size() - x.size()) / 2);
	return dap;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		v[x % m].push_back(x);
	}
	for(int i=0; i<m; i++){
		sort(v[i].begin(), v[i].end());
	}
	int ret = 0;
	for(int i=0; i<=m-i; i++){
		if(2 * i == m || i == 0){
			ret += v[i].size() - v[i].size() % 2;
		}
		else{
			ret += solve(v[i], v[m-i]);
		}
	}
	cout << ret / 2 << endl;
}
