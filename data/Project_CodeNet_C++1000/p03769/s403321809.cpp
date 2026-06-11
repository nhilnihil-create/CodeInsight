#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	long long int N; 
	cin >> N; 
	//12…m12…mで(2^m)-1通りできる．
	//12…m(m+1)12…i(m+1)(i+1)…mとすると2^i通り増える．
	//これを繰り返してNにする．高々160文字くらいなので制約もOK．
	vector<int> ans; 
	long long int P[50] = {};
	P[0] = 0;
	for(int i = 1; i <= 45; i++){
		P[i] = 2 * P[i-1] + 1;
	}
	int R = (upper_bound(P, P+45, N) - P) - 1; 
	for(int i = 1; i <= R; i++){
		ans.push_back(i); 
	}
	long long int S = N - P[R]; 
	int count = R; 
	for(int j = 45; j >= 0; j--){
		long long int T = (S >> j); 
		if(T & 1){
			count ++; 
			ans.insert(ans.begin() + j, count); 
		}
	}
	int A = ans.size(); 
	cout << A * 2 << endl; 
	for(int i = 1; i <= A; i++){
		cout << i << " "; 
	}
	for(int i = 0; i < A; i++){
		cout << ans.at(i) << " "; 
	}
	cout << endl; 
}