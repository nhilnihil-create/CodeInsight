#include <bits/stdc++.h>
#include <queue>
using namespace std;
int main(){
	int N, K; 
	cin >> N >> K; 
	vector<int> E[2010] = {}; 
	int A[2010] = {}; int B[2010] = {}; 
	for(int i = 0; i < N-1; i++){
		cin >> A[i] >> B[i]; 
		A[i] --; B[i] --; 
		E[A[i]].push_back(B[i]); 
		E[B[i]].push_back(A[i]); 
	}
	int D[2010] = {}; 
	int ans = 114514; 
	if(K % 2 == 0){
	for(int c = 0; c < N; c++){
		fill(D, D+2005, -1); 
		queue<int> que; 
		que.push(c); D[c] = 0; 
		while(que.size()){
			int p = que.front(); que.pop(); 
			for(int i = 0; i < E[p].size(); i++){
				if(D[E[p].at(i)] == -1){
					D[E[p].at(i)] = D[p] + 1; 
					que.push(E[p].at(i)); 
				}
			}
		}
		int ok = 0;
		for(int j = 0; j < N; j++){
			if(D[j] <= K/2) ok ++; 
		}
		ans = min(ans, N - ok); 
	}
	cout << ans << endl; 
	}
	if(K % 2 == 1){
	for(int c = 0; c < N-1; c++){
		fill(D, D+2005, -1); 
		queue<int> que; 
		que.push(A[c]); que.push(B[c]); 
		D[A[c]] = 0; D[B[c]] = 0; 
		while(que.size()){
			int p = que.front(); que.pop(); 
			for(int i = 0; i < E[p].size(); i++){
				if(D[E[p].at(i)] == -1){
					D[E[p].at(i)] = D[p] + 1; 
					que.push(E[p].at(i)); 
				}
			}
		}
		int ok = 0;
		for(int j = 0; j < N; j++){
			if(D[j] <= K/2) ok ++; 
		}
		ans = min(ans, N - ok); 
	}
	cout << ans << endl; 
	}	
}