#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int N, a[MAXN], c[MAXN];

int main(){
	scanf("%d", &N);
	
	int D = 0;
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	
		D = max(D, a[i]);
		c[a[i]]++;
	}
	
	int d = D;
	while(2 * d >= D){
		if(2 * d == D){
			if(c[d] < 1){
				printf("Impossible\n");
				return 0;
			}
			c[d]--;
		}else{
			if(c[d] < 2){
				printf("Impossible\n");
				return 0;	
			}
			c[d] -= 2;
		}
		d--;
	}
	
	for(int i = 1; i <= (D + 1) / 2; i++){
		if(c[i] > 0){
			printf("Impossible\n");
			return 0;		
		}
	}
	
	printf("Possible\n");
	
	return 0;
}
