#include <bits/stdc++.h>
using namespace std;
int N; 
long long A[100010]; 
vector<int> E[100010];  
long long up[100010]; // その頂点から上に出る回数
bool ok = true; 
void dfs(int now, int parent){
	if(E[now].size() == 1){
		up[now] = A[now]; return; 
	}
	long long m = 0; long long sum = 0;
	for(int i = 0; i < E[now].size(); i++){
		if(E[now].at(i) == parent) continue; 
		dfs(E[now].at(i), now); 
		m = max(m, up[E[now].at(i)]); 
		sum += up[E[now].at(i)];
	}
	if(A[now] > sum || A[now] < m || A[now] < (sum + 1)/2){
		ok = false; return; 
	}
	up[now] = 2 * A[now] - sum; 
}
int main(){
	cin >> N; 
	for(int i = 0; i < N; i++) cin >> A[i];
	if(N == 2){
		cout << (A[0] == A[1] ? "YES" : "NO") << endl;
		return 0; 
	}
	for(int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b; 
		a--; b--; 
		E[a].push_back(b); E[b].push_back(a); 
	}	
	int idx = -1; 
	for(int i = 0; i < N; i++){
		if(E[i].size() > 1){
			idx = i; break; 
		}
	}
	E[N].push_back(idx); E[idx].push_back(N); 
	dfs(idx, N); 
	cout << ((ok && up[idx] == 0)? "YES" : "NO") << endl;  
}