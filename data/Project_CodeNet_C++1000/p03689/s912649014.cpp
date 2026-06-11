#include<bits/stdc++.h>
using namespace std;
const int v=1e3;int n,m,a,b,s,q[v][v];
main()
{
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;s+=q[i][j]=(i%a||j%b)?v:-(a*b-1)*v-1,j++);
	if(s<=0)return 0&puts("No");puts("Yes");
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;printf("%d ",q[i][j]),j++);
}
