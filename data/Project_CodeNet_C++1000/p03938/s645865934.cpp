#include <bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int n,p;
int a[N],b[N];
int main(){
	scanf("%d",&n);
	for (register int i=1; i<=n; ++i) a[i]=i*20001;
	for (register int i=1; i<=n; ++i) b[i]=(n-i+1)*20001;
	for (register int i=1; i<=n; ++i) 
	{
		scanf("%d",&p);
		b[p]-=(n-i+1);
	}
	for (register int i=1; i<=n; ++i) printf("%d ",a[i]); puts("");
	for (register int i=1; i<=n; ++i) printf("%d ",b[i]);
return 0;	
}