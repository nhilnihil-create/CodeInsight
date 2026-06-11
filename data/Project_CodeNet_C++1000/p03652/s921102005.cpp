#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
	int N, M; 
	cin >> N >> M; 
	vector<int> A[310] = {}; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int a; 
			cin >> a; 
			A[i].push_back(a); 
		}
	}
	int ans = 314; 
	for(int q = 0; q < M; q++){
		int count[310] = {}; // 現時点で一番好きなスポーツの種類をカウント
		for(int i = 0; i < N; i++){
			count[A[i].at(0)] ++;  
		}
		int mx = 0; int ind = 0; 
		for(int j = 1; j <= M; j++){
			if(mx < count[j]){
				ind = j; 
				mx = max(mx, count[j]);
			} 
		}
		ans = min(mx, ans); 
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(A[i].at(j) == ind){
					A[i].erase(A[i].begin() + j); //最大値を与えるスポーツの1つを除去
					break; 
				}
			}
		}
	}
	cout << ans << endl; 
}