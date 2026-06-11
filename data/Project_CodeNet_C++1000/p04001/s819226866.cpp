#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

char s[maxn];
int n;
ll ans;

void dfs(int i, ll val, ll sum){
	if(i > n){
		ans += sum + val;
		return;
	}
	if(val) dfs(i + 1, s[i] - '0', sum + val);
	dfs(i + 1, val * 10 + s[i] - '0', sum);
}

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	dfs(1, 0, 0);
	printf("%lld", ans);
}