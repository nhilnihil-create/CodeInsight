#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int N; 
	cin >> N; 
	long long int X[100010] = {}; 
	long long int D[100010] = {}; 
	for(int i = 0; i < N; i++){
		cin >> X[i]; 
	}
	for(int i = 1; i < N; i++){
		D[i] = X[i] - X[i-1]; 
	}
	int M; 
	long long int K; 
	cin >> M >> K; 
	int A[100010] = {}; // 1セットでどこに移るか
	for(int i = 1; i < N; i++){
		A[i] = i; 
	}
	for(int i = 0; i < M; i++){
		int a; 
		cin >> a; 
		swap(A[a-1], A[a]); 
	}
	int E[100010] = {}; // K回後の距離の添字
	for(int i = 1; i < N; i++){
		if(E[i]) continue; 
		vector<int> Y; 
		Y.push_back(i); 
		int k = i; 
		for(int j = 0; j < 114514; j++){
			k = A[k];
			if(k != Y.at(0)){
				Y.push_back(k); 
			}
			else{
				int P = (int)(K % Y.size()); 
				for(int l = 0; l < Y.size(); l++){
					E[Y.at(l)] = Y.at((P+l) % Y.size()); 
				}
				break; 
			}
		}
	}
	long long int z = X[0]; 
	cout << X[0] << endl; 
	for(int i = 1; i < N; i++){
		cout << z + D[E[i]] << endl; 
		z += D[E[i]]; 
	}
}