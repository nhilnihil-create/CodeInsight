#include<bits/stdc++.h>
#define inf 0x7fffffff
#define RG register
#define maxn 500005
#define maxm 205
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}
    return x * f;
}
 
int n, k;
ll ans;
char ch[11];
void dfs(int now,ll lasnum,ll sum){
	if(now == n){
		sum += lasnum;
		ans += sum;
		return ;
	}
	dfs(now + 1, lasnum * 10 + ch[now + 1] - '0', sum);
	dfs(now + 1, ch[now + 1] - '0', sum + lasnum);
}
int main(){
	int i, j, x, l, r, mid;
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	dfs(1, ch[1] - '0', 0);
	printf("%lld\n", ans);
	return 0;
}