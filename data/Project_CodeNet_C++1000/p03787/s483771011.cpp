#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int N, M; 
vector<int> E[200010]; 
int par[200010]; 
int depth[200010]; 
int size[200010] = {}; 
void init(){
	for(int i = 0; i < N * 2; i++){
		par[i] = i; depth[i] = 0; size[i] = 1; 
	}
}
int find(int x){
	if(par[x] == x){
		return x;
	}
	else{
		return par[x] = find(par[x]); 
	}
}
void unite(int x, int y){
	x = find(x); 
	y = find(y); 
	if(x == y) return;
	else if(depth[x] < depth[y]){
		par[x] = y; 
		size[y] += size[x]; 
	}else{
		par[y] = x; 
		size[x] += size[y];  
		if(depth[x] == depth[y]) depth[x] ++; 
	}
}
bool same(int x, int y){
	return find(x) == find(y); 
}
int siz(int x){
	return size[find(x)]; 
}
int main(){
	cin >> N >> M; 
	init(); 
	for(int i = 0; i < M; i++){
		int a, b; cin >> a >> b; 
		a--; b--; 
		unite(a, b+N); unite(b, a+N); 
	}
	long long nibu = 0; long long notnibu = 0; long long koritu = 0; 
	bool seen[200010] = {}; 
	for(int i = 0; i < N; i++){
		if(seen[find(i)]) continue; 
		if(find(i) == find(i+N)) notnibu ++; 
		else if(siz(i) == 1) koritu ++; 
		else nibu ++; 
		seen[find(i)] = true; seen[find(i+N)] = true; 
	}
	long long ans = nibu * nibu + (nibu + notnibu) * (nibu + notnibu) + 2 * (long long) N * koritu - koritu * koritu; 
	cout << ans << endl; 
}