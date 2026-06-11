#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	for(;!isdigit(ch);ch = getchar())if(ch == '-')f = -f;
	for(;isdigit(ch);ch = getchar())x = 10 * x + ch - '0';
	return x * f;
}
const int maxn = 1e5 + 10;
int n,k,ans;
int a[maxn],dep[maxn];
vector<int> G[maxn];
inline int dfs(int x,int fa)
{
	dep[x] = dep[fa] + 1;
    int mx = dep[x];
    for(auto to : G[x])mx = max(dfs(to,x),mx);
    if(x == 1)return 0;
    if(fa != 1 && mx - dep[x] + 1 == k) ans++,mx = 0;
    return mx;
}
int main()
{
	n = read(),k = read();
	for(int i=1;i<=n;i++)
	{
		a[i] = read();
		if(i != 1)G[a[i]].push_back(i);
	}
	if(a[1] != 1)ans++;
	dep[0] = -1;
	dfs(1,0);
	printf("%d",ans);
}