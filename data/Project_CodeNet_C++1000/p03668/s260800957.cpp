#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
using namespace std;
typedef long long LL;
const int N=2e5;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
vector<int>v[N];
inline int dfs(int k,int fa=0) {
	int ans=0;
	for (int t:v[k])
		if (t!=fa)
			ans^=dfs(t,k)+1;
	return ans;
}
int main()
{
	int n=gi(),a,b;
	while (--n) v[a=gi()].push_back(b=gi()),v[b].push_back(a);
	puts(dfs(1)?"Alice":"Bob");
	return 0;
}
