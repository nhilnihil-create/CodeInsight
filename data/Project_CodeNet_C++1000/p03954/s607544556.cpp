#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int A[200010];
	for(int i = 1; i < N * 2; i++) cin >> A[i];
	int B[200010];
	int ok = 1; int ng = N * 2 - 1;
	while(ng - ok > 1){
		int top = 0;
		int mid = (ng + ok) / 2;
		for(int i = 1; i < N * 2; i++){		
			if(A[i] >= mid) B[i] = 1;
			else B[i] = 0;
		}
		int L = 1; int R = N * 2 - 1;
		if(B[N] == B[N + 1] || B[N] == B[N - 1]){
			top = B[N];
			if(top) ok = mid;
			else ng = mid;
			continue;
		}
		for(int i = N; i < N * 2 - 1; i++){
			if(B[i] == B[i + 1]){
				R = i; break;
			}
		}
		for(int i = N; i > 1; i--){
			if(B[i] == B[i - 1]){
				L = i; break;
			}
		}
		if(L == 1 && R == N * 2 - 1) top = B[1]; 
		else if(L % 2 == R % 2){
			top = B[L];
		}else if(L + R < N * 2){
			top = B[R];
		}else{
			top = B[L];
		}
		if(top) ok = mid;
		else ng = mid;
	}
	cout << ok << "\n";
}