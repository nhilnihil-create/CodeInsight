#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	int X[100010] = {}; 
	for(int i = 0; i < N; i++) cin >> X[i]; 
	int L, Q; cin >> L >> Q; 
	int A[100010][18] = {}; //A[iから始めて][2^j日で進める]
	for(int i = 0; i < N; i++){
		int a = upper_bound(X, X+N, X[i] + L) - X; 
		A[i][0] = a - 1; 
	}
	for(int j = 1; j < 18; j++){
		for(int i = 0; i < N; i++){
			A[i][j] = A[A[i][j-1]][j-1]; 
		}
	}
	for(int q = 0; q < Q; q++){
		int a, b; cin >> a >> b; 
		a--; b--; 
		if(a > b) swap(a, b); 
		int now = a; 
		int ans = 0; 
		for(int i = 17; i >= 0; i--){
			if(A[now][i] >= b) continue;  
			now = A[now][i]; 
			ans += (1 << i); 
		}
		cout << ans + 1 << endl; 
	}
}