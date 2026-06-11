#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
vector<LL> edges[110000];
LL num[110000];
vector<LL> deg(110000, 0);
LL ok = 1;
void dfs(LL v, LL p){

	if(deg[v] != 1) num[v] *= 2;
	vector<LL> r;
	for (LL x : edges[v]) {
		if (x != p){
			dfs(x, v);
			num[v] -= num[x];
			r.push_back(num[x]);
		}
	}
	if(num[v] < 0) ok = 0;
	if(v > 0) r.push_back(num[v]);
	sort(r.begin(), r.end());
	reverse(r.begin(), r.end());
	LL sum = 0;
	for(LL x : r){
		sum += x;
	}
	if(deg[v] > 1 && (sum % 2) != 0) ok = 0;
	if(deg[v] > 1 && r[0] * 2 > sum) ok = 0;
}
int main(){
	cin >> n;
	for(LL i = 0; i < n; i++){
		cin >> num[i];
	}
	for(LL i = 0; i < n-1; i++){
		LL a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
		deg[a]++; deg[b]++;
	}
	dfs(0, -1);
	if(num[0] != 0 || ok == 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}
