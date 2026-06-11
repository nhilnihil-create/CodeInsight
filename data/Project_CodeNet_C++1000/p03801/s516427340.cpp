#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N; 
	long long A[100010] = {};
	int mx = 0; 
	vector<int> place, value; 
	place.push_back(0); value.push_back(0); 
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		if(A[i] > mx){
			mx = A[i]; place.push_back(i); 
			value.push_back(A[i]); 
		}
	}
	long long Full[100010] = {}; 
	long long full[100010] = {}; 
	long long ans[100010] = {}; 
	for(int i = 1; i <= N; i++){
		int a = lower_bound(value.begin(), value.end(), A[i]) - value.begin(); 
		ans[place[a]] += A[i] - value[a-1]; 
		Full[a-1] ++; 
	}
	for(int i = N + 2; i >= 0; i--){
		full[i] = full[i+1] + Full[i]; 
	}
	for(int i = 1; i < place.size(); i++){
		ans[place[i]] += (value[i] - value[i-1]) * full[i]; 
	}
	for(int i = 1; i <= N; i++) cout << ans[i] << "\n"; 
}