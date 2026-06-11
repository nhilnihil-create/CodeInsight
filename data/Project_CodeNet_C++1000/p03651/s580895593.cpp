#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int n, k, s[100005];

int main(){
	scanf("%d %d", &n, &k);
	bool bigger = false;
	int g = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
		if(s[i] >= k){
			bigger = true;
		}
		g = gcd(g, s[i]);
	}
	
	if(bigger && k % g == 0){
		printf("POSSIBLE\n");
	}else{
		printf("IMPOSSIBLE\n");
	}
	return 0;
}