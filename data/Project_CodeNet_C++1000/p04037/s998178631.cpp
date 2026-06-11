#include <bits/stdc++.h>
using namespace std;
int dist(pair<int, int> p, pair<int, int> q){
	return abs(p.first - q.first) + abs(p.second - q.second); 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	int N; cin >> N; 
	int A[114514] = {}; 
	for(int i = 1; i <= N; i++) cin >> A[i]; 
	sort(A+1, A+N+1, greater<int>());
	vector<pair<int, int>> V; 
	V.emplace_back(0, A[1]); 
	bool ans = true; 
	for(int i = 1; i <= N; i++){
		if(A[i] == A[i+1]) continue; 
		V.emplace_back(i, A[i]); 
		V.emplace_back(i, A[i+1]); 
	}
	int idx = -1; bool equal = false; 
	for(int i = 0; i < V.size(); i++){
		int a = V[i].first; int b = V[i].second; 
		if(b == a){
			idx = i; equal = true; break; 
		}else if(b < a){
			idx = i; break; 
		}
	}
	if(equal && (idx & 1)){
		ans = false; 
	}else if(equal){
		int d1 = dist(V[idx + 1], V[idx]); 
		int d2 = dist(V[idx], V[idx - 1]); 
		if(!(d1 & 1) && !(d2 & 1)) ans = false;  
	}else if(idx & 1){
		if(!((V[idx].first + V[idx].second) & 1)) ans = false; 
	}else{
		if(!((V[idx-1].first + V[idx-1].second) & 1)) ans = false; 
	}
	cout << (ans ? "First" : "Second") << "\n";
}