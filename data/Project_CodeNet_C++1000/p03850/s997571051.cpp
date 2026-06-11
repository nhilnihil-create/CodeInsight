#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=1e5+10;
char op[MAXN];
int n,dat[MAXN],nxt[MAXN],fst;
ll suf[MAXN],cur,res=-1ll<<60;

int main()
{
	scanf("%d%d",&n,&fst);
	for(int i=1;i<n;i++)
		scanf(" %c%d",&op[i],&dat[i]);
	cur=n;
	for(int i=n-1;i;i--)
	{
		suf[i]=suf[i+1]+dat[i];
		if(op[i]=='-') nxt[i]=cur,cur=i;
	}
	cur=0;
	for(int i=1;i<n;i++)
		if(op[i]=='-') 
			res=max(res,cur-suf[i]+2*suf[nxt[i]]),cur-=dat[i];
		else cur+=dat[i];
	res=max(res,cur);
	printf("%lld",res+fst);
	return 0;
}