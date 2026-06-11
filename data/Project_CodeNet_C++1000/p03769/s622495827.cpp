#include <bits/stdc++.h>
using namespace std;

typedef long long  LL;
LL n;
int m;
deque <int> a,b;

void solve(LL n)
{
	if (n==0)  return;
	if (n&1)  solve(n/2),m++,a.push_back(m),b.push_back(m);
	else  solve(n-1),m++,a.push_back(m),b.push_front(m);
}

void work()
{
	scanf("%lld",&n);
	solve(n);
	printf("%d\n",a.size()+b.size());
	for (int i=0; i<a.size(); i++)  printf("%d ",a[i]);
	for (int i=0; i<b.size(); i++)  printf("%d ",b[i]);
}

int main()
{
	work();
	return 0;
}
