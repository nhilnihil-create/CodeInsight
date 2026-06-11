#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN],n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int cur=1;
	while(a[cur]>=cur) ++cur;
	--cur;
	int up=(a[cur]-cur)&1^1;
	int nxt=cur;
	while(a[nxt]>=cur) ++nxt; 
	--nxt;
	int rt=(nxt-cur)&1^1;
	puts(up&&rt?"Second":"First");
	return 0;
}