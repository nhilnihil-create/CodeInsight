#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int>X;
	vector<int>Y;
	for (int i = 0; i < N; ++i) {
		if (0 == i%2) {
			X.push_back(A[i]);
		}
		else {
			Y.push_back(A[i]);
		}
	}
	vector<int>Ans(N);
	for (int i = 0;i<Y.size();++i) {
		Ans[i] = Y[Y.size()-1-i];
	}
	for (int i = 0;i<X.size();++i) {
		Ans[Y.size()+i] = X[i]; 
	}
	if (1 == N%2) {
		reverse(Ans.begin(),Ans.end());
	}
	for (int i = 0; i < N; ++i) {
		if(0 !=i){
			cout << " ";
		}
		cout << Ans[i];
	}
	return 0;
}