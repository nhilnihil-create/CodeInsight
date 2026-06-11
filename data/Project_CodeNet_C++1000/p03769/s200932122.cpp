#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<deque>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
#define ll long long
using namespace std;
const int N=50;
int a[N],tot=0;
deque<int> q;
void dfs(ll x){
	if(x==1) return;
	if(x&1) dfs(x-1),q.push_front(++tot);
	else dfs(x>>1),q.push_back(++tot);
}
int main()
{
	ll n;
	scanf("%lld",&n);
	dfs(n+1),printf("%d\n",tot<<1);
	fo(i,0,tot-1) printf("%d ",q[i]);
	fo(i,1,tot) printf("%d ",i);
}
