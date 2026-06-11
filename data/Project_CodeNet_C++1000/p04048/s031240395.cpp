#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
LL n,x;
LL work(LL l1,LL l2) {
	if(!l2) return -l1;
	return work(l2,l1%l2)+2*(l1/l2)*l2;
}
int main()
{
	scanf("%lld%lld",&n,&x);
	printf("%lld\n",work(x,n-x)+n);
	return 0;
}