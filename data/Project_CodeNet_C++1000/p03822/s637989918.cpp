#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
	int N; 
	cin >> N; 
	int A[100010] = {}; 
	int I[100010] = {}; 
	vector<int> E[100010] = {}; // 出ていく辺
	vector<int> F[100010] = {}; // 入ってくる辺
	for(int i = 2; i <= N; i++){
		int a; 
		cin >> a; 
		E[i].push_back(a); 
		F[a].push_back(i); 
		I[a] ++; 
	}
	stack<int> st;
	for(int i = 1; i <= N; i++){
		if(!I[i]) st.push(i); 
	}
	vector<int> S = {}; //トポロジカルソート後
	while(st.size()){
		int i = st.top(); st.pop(); 
		S.push_back(i); 
		for(int j = 0; j < E[i].size(); j++){
			I[E[i].at(j)] --; 
			if(I[E[i].at(j)] == 0) st.push(E[i].at(j)); 
		}
	}
	int dp[100010] = {}; 
	for(int i = 0; i < N; i++){
		vector<int> ord = {}; 
		for(int k = 0; k < F[S[i]].size(); k++){
			ord.push_back(dp[F[S[i]].at(k)]);  
		}
		sort(ord.begin(), ord.end()); 
		int tmp = 0; 
		for(int j = 0; j < ord.size(); j++){
			tmp = max(tmp + 1, ord[j] + 1); 
		}
		dp[S[i]] = tmp; 
	}
	cout << dp[1] << endl; 
}