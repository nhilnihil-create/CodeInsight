#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[100005];
vector<int> G[100005];

int dfs(int v, int prev)
{
	if(G[v].size() == 1) return a[v];
	int sum = 0; vector<int> vec;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		int res = dfs(G[v][i], v);
		if(res == -1) return -1;
		vec.push_back(res);
		sum += res;
	}
	sort(vec.begin(), vec.end());
	
	if(a[v] > sum) return -1;
	if(vec.size() == 1) return vec[0];
	
	int mx = vec.back(), kmax;
	if(sum % 2){
		vec.back()--;
		mx = max(vec.back(), vec[vec.size()-2]);
	}
	if(vec.size() == 2) kmax = min(vec[0], vec[1]);
	else{
		if(mx >= sum/2){
			kmax = sum - mx;
			if(sum % 2) kmax--;
		}
		else kmax = sum/2;
	}
	
	int k = sum - a[v];
	if(k <= kmax && sum - 2*k >= 0) return sum - 2*k;
	else return -1;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if(n == 2){
		if(a[1] == a[2]) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	
	int root;
	for(int i = 1; i <= n; i++){
		if(G[i].size() > 1){
			root = i;
			break;
		}
	}
	if(dfs(root, -1) == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}