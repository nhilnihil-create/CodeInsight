#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int n,m;
const int N=1e5+4;
int f[N];
int32_t main()
{
	n=in();m=in();
	for(int i=1;i<=m;i++){int x=in();int y=in();f[y]++;f[x]++;}
	bool ok=1;
	for(int i=1;i<=n;i++)ok&=(f[i]%2==0);
	
	if(!ok){puts("NO");return 0;}
	puts("YES");
}
