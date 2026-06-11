#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int N; 
	cin >> N; 
	pair<int, int> X[510] = {}; 
	int Y[510] = {}; 
	int A[250010] = {}; // 解答用の配列
	for(int i = 0; i < N; i++){
		cin >> X[i].first; 
		Y[i] = X[i].first; 
		X[i].second = i+1; 
		A[X[i].first-1] = i+1; 
	}
	sort(X, X+N); 
	vector<int> L = {}; // 指定箇所よりも左を貪欲に
	vector<int> R = {}; // 指定箇所よりも右を貪欲に
	for(int i = 0; i < N; i++){
		for(int j = 0; j < X[i].second-1; j++){
			L.push_back(X[i].second); 
		}
		for(int j = 0; j < N-X[i].second; j++){
			R.push_back(X[i].second); 
		}
	}
	int l = 0, r = 0; 
	for(int i = 0; i < N * N; i++){
		if(A[i]) continue; 
		else if(l < N * (N - 1) / 2){
			A[i] = L.at(l); 
			l++; 
		}
		else{
			A[i] = R.at(r); 
			r++;
		}
	}
	vector<int> B[510] = {}; // 最後に十分性の確認
	for(int i = 0; i < N * N; i++){
		B[A[i]].push_back(i+1); 
	}
	string ans = "Yes"; 
	for(int i = 1; i <= N; i++){
		if(B[i].at(i-1) != Y[i-1]) ans = "No"; 
	}
	cout << ans << endl; 
	if(ans == "Yes"){
		for(int i = 0; i < N * N; i++){
			cout << A[i] << " "; 
		}
		cout << endl; 
	}
}