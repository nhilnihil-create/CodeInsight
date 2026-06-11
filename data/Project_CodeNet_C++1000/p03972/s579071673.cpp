#include <bits/stdc++.h>
using namespace std;
int main(){
	int W, H; 
	cin >> W >> H; 
	pair<long long int, int> A[200010] = {}; 
	for(int i = 0; i < W; i++){
		cin >> A[i].first; 
		A[i].second = 1;
	}
	for(int j = 0; j < H; j++){
		cin >> A[j+W].first; 
		A[j+W].second = 2; 
	}
	sort(A, A+H+W); 
	long long int horizontal = (long long) H+1; 
	long long int vertical = (long long) W+1; 
	long long int ans = 0; 
	for(int i = 0; i < H+W; i++){
		if(A[i].second == 1){
			ans += horizontal * A[i].first; 
			vertical --; 
		}
		if(A[i].second == 2){
			ans += vertical * A[i].first; 
			horizontal --; 
		}
	}
	cout << ans << endl;  
}