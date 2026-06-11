#include<cstdio>
#include<deque>
#define LL long long
using namespace std;
typedef deque<int>::iterator diter;
LL n;
int cnt;
deque<int> x,y;
void solve(LL n)
{
	if(n==1) return;
	solve(n/2);
	x.push_front(++cnt); y.push_front(cnt);
	if(n&1) { x.push_front(++cnt); y.push_back(cnt); }
}
int main()
{
	scanf("%lld",&n); n++;
	solve(n);
	printf("%d\n",cnt*2);
	for(diter it=x.begin();it!=x.end();it++) printf("%d ",*it);
	for(diter it=y.begin();it!=y.end();it++) printf("%d ",*it);
}
