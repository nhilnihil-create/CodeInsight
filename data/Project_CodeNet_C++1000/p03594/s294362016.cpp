#include<bits/stdc++.h>
using namespace std;
int n, m, d;
int main(){
	scanf("%d%d%d", &n, &m, &d);
	string s = "RYGB";
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			int x = (i + j + 10000) / d, y = (i - j + 10000) / d;
			x &=1, y &= 1;
			printf("%c", s[x * 2 + y]);
		}printf("\n");
	}
		
	
	
	return 0;
}