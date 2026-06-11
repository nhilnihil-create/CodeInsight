#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;

const int maxn = 2e5 + 5;
int n;
char s[maxn];

struct automaton{
  int son[maxn][26], lst[maxn];
  int dp[maxn], nxt[maxn];

  void build(){
	per(i, n, 0){
	  rep(j, 0, 25) son[i][j] = lst[j];
	  lst[s[i] - 'a'] = i;
	}
  }

  void dfs(int u){
	printf("%c", 'a' + nxt[u]);
	if(dp[u] == 0) return ;
	dfs(son[u][nxt[u]]);
  }

  void sol(){
	per(i, n, 0){
	  dp[i] = n;
	  rep(j, 0, 25){
		if(son[i][j] == 0){
		  dp[i] = 0;
		  nxt[i] = j;
		  break;
		}
		else{
		  if(dp[son[i][j]] + 1 < dp[i]){
			dp[i] = dp[son[i][j]] + 1;
			nxt[i] = j;
		  }
		}
	  }
	}
	dfs(0);
	puts("");
  }
}am;

int main(){
  scanf("%s", s + 1);
  n = strlen(s + 1);
  am.build();
  am.sol();
  return 0;
}
