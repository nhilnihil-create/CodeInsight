#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; int A[110] = {}; 
	cin >> N; 
	int mx = 0; 
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		mx = max(mx, a);  
		A[a] ++; 
	}
	bool possible = true; 
	for(int i = 0; i < (mx+1)/2; i++){
		if(A[i] > 0) possible = false; 
	}
	if(mx % 2 == 0){
		if(A[mx / 2] != 1) possible = false; 
		for(int i = mx / 2 + 1; i <= mx; i++){
			if(A[i] < 2) possible = false; 
		}
	}
	else if(mx % 2 == 1){
		if(A[(mx + 1) / 2] != 2) possible = false; 
		for(int i = (mx + 1) / 2; i <= mx; i++){
			if(A[i] < 2) possible = false; 
		}
	}
	if(possible) cout << "Possible" << endl; 	
	else cout << "Impossible" << endl; 
}