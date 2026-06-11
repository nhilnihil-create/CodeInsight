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
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int main()
{
	deque<int>q;
	LL n;cin>>n;n++;int tot=0,i;
	for (i=40;!(n>>i&1);i--);
	while (i--) {
		q.push_back(++tot);
		if (n>>i&1)
			q.push_front(++tot);
	}
	printf("%d\n",tot<<1);
	for (auto k:q) printf("%d ",k);
	for (int i=1;i<=tot;i++) printf("%d ",i);
	return 0;
}
