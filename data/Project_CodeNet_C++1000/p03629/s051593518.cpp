#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, ne[N][26] , now[26], t = 1 , xxy , dp[N];
char s[N];

void dfs(int x) {
    for(int i = 0;i < 26;++ i) if(!ne[x][i]) {
	    putchar(i + 'a'); exit(0);
	}
    int Min = 2e9;
    for(int i = 0;i < 26;++ i) {
	Min = min(Min , dp[ne[x][i]]);
    }
    for(int i = 0;i < 26;++ i) {
	if(Min == dp[ne[x][i]]) {
	    putchar(i + 'a'); dfs(ne[x][i]);
	    return;
	}
    }
}

int main(void) {
    scanf("%s" , s + 1);
    n = strlen(s + 1);
    for(int i = n;i >= 0;-- i) {
	dp[i] =2e9;
	for(int j = 0;j < 26;++ j) {
	    ne[i][j] = now[j];
	    dp[i] = min(dp[i] , dp[ne[i][j]]);
	}
	int sby = 1;
	for(int j = 0;j < 26;++ j) {
	    sby &=(!!now[j]);
	}
	dp[i] += sby;
	if(i == 0) break;
	now[s[i] - 'a'] = i;
	xxy |= (1 << (s[i] - 'a'));
	if(xxy == (1 << 26) - 1) {
	    ++ t; xxy = 0;
	}
    }
    dfs(0);
}
