#include <bits/stdc++.h>
using namespace std; 
int main(){
	int N, M; cin >> N >> M; 
	int cnt[100010] = {}; 
	for(int i = 0; i < N; i++){
		int a; cin >> a; cnt[a] ++; 
	}
	int sum[100010] = {}; 
	int odd[100010] = {}; 
	for(int i = 1; i <= 100000; i++){
		sum[i % M] += cnt[i]; 
		if(cnt[i] % 2) odd[i % M] ++; 
	}
	int rem = 0; 
	rem += odd[0] % 2; 
	if(M % 2 == 0) rem += odd[M/2] % 2; 
	for(int i = 1; i < (M+1)/2; i++){
		if(sum[i] <= sum[M-i]){
			rem += max(odd[M-i] - sum[i], 0); 
			if(odd[M-i] < sum[i] && odd[M-i] % 2 != sum[i] % 2) rem ++;  
		}
		else{
			rem += max(odd[i] - sum[M-i], 0); 
			if(odd[i] < sum[M-i] && odd[i] % 2 != sum[M-i] % 2) rem ++;  
		}
	}
	cout << (N - rem) / 2 << endl; 
}