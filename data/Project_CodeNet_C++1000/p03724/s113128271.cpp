#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+10;
int n,m,d[N];
signed main(){
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++)	cin>>a>>b,d[a]++,d[b]++;
	for(int i=1;i<=n;i++)	if(d[i]&1)	return puts("NO"),0;
	puts("YES");
	return 0;
}
