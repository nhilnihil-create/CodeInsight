#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,i,x,y,mx,a[1000010];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x]^=1;a[y]^=1;
	}
	for(i=1;i<=n;i++)if(a[i])return puts("NO"),0;
	puts("YES");
}