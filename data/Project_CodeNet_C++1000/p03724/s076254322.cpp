#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,x,y,d[N];
int main(){
	scanf("%d%d",&n,&m);
	while (m--)scanf("%d%d",&x,&y),d[x]^=1,d[y]^=1;
	int cnt=0;
	for (int i=1;i<=n;i++)cnt+=d[i];
	if (cnt>1)puts("NO");
	else puts("YES");
}
