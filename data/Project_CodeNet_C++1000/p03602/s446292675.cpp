#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
static const int INF = 1 << 30;
int main(){
	int N;
	ll A[300][300];
	ll B[300][300];

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			B[i][j] = INF;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &A[i][j]);
			B[i][j] = A[i][j];
		}
	}

	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
			}
		}
	}
	bool def = true;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(B[i][j] < A[i][j]) def = false;
		}
	}

	ll ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			bool nukemichi = false;
			for(int k = 0; k < N; k++){
				if(i == k || j == k) continue;
				if(B[i][j] == B[i][k] + B[k][j]){
					nukemichi = true;
				}
			}
			if(nukemichi == false) ans += B[i][j];
		}
	}
	if(def == false) printf("-1\n");
	else printf("%lld\n", ans / 2);
	return 0;
}
