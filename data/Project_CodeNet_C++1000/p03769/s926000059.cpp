#include<cstdio>
#include<deque>
using namespace std;
typedef long long LL;
deque <int> q;
LL n;
int i,j,k,g,l;

void solve(LL n)
{
	if (n==1)
		q.push_front(++l);
	else
		if (n&1)
			solve(n>>1),
			q.push_back(++l);
		else
			solve(n-1),
			q.push_front(++l);
}

int main()
{
	scanf("%lld",&n);
	solve(n);
	printf("%d\n",l<<1);
	for (i=0;i<l;++i) printf("%d ",q[i]);
	for (i=1;i<=l;++i) printf("%d ",i);
	return 0;
}