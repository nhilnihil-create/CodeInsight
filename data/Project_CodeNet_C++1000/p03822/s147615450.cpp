#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int ans[N],a[N],at;
vector <int> son[N];
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
void solve(int x){
	ans[x]=1;
	for (auto y : son[x])
		solve(y);
	at=0;
	for (auto y : son[x])
		a[++at]=ans[y];
	sort(a+1,a+at+1);
	reverse(a+1,a+at+1);
	for (int i=1;i<=at;i++)
		ans[x]=max(ans[x],a[i]+i);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		son[i].clear();
	for (int i=2;i<=n;i++)
		son[read()].push_back(i);
	memset(ans,0,sizeof ans);
	solve(1);
	printf("%d",ans[1]-1);
	return 0;
}