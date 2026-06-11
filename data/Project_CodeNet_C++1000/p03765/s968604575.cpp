#include <bits/stdc++.h>

using namespace std;

char S[101010], T[101010];
int X[101010], Y[101010];
int n;

int main()
{
	int q, i, a, b, c, d;
	
	scanf("%s%s", S + 1, T + 1);
	
	for(i=1; S[i]; i++){
		X[i] = X[i - 1] + 1 + (S[i] == 'B');
	}
	
	for(i=1; T[i]; i++){
		Y[i] = Y[i - 1] + 1 + (T[i] == 'B');
	}
	
	scanf("%d", &q);
	
	for(; q--; ){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%s\n", (X[b] - X[a - 1]) % 3 == (Y[d] - Y[c - 1]) % 3? "YES" : "NO");
	}
	
	return 0;
}