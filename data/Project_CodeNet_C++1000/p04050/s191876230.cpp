#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
#define bf(i,s) for(int i = head[s]; i; i = e[i].next)
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define VI vector<int>
#define sf scanf
#define pf printf
#define fp freopen
#define SZ(x) ((int)(x).size())
#define IF_DEBUG 0
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int inf = 1<<30;
const ll INF = 1ll<<60;
const db Inf = 1e20;
const db eps = 1e-9;

void gmax(int &a,int b){a = (a > b ? a : b);}
void gmin(int &a,int b){a = (a < b ? a : b);}

const int maxn = 105;

int n, m, nb, a[maxn], odd, ra[maxn], b[maxn];
bool used[maxn];

int main()
{
	sf("%d%d",&n,&m);
	fo(i,1,m) sf("%d",&a[i]), odd += (a[i]&1);
	if(odd > 2) return 0*pf("Impossible");
	if(m == 1)
	{
		if(a[1] == 1) pf("1\n1\n1\n");
		else pf("%d\n2\n%d %d\n",a[1],a[1]-1,1);
		return 0;
	}
	fo(i,1,m) if(a[i]%2==1)
	{
		if(!ra[1]) ra[1] = a[i];
		else ra[m] = a[i];
		used[i] = true;
	}
	int cnt = 1;
	fo(i,1,m) if(!used[i]) 
	{
		while(cnt <= m && ra[cnt]) ++ cnt;
		ra[cnt] = a[i];
	}
	if(ra[1] == ra[m] && ra[1] == 1)
	{
		b[1] = 2;
		fo(i,2,m-1) b[i] = ra[i];
		fo(i,1,m) pf("%d ",ra[i]); pf("\n");
		pf("%d\n",m-1);
		fo(i,1,m-1) pf("%d ",b[i]);
		return 0;
	}
	else if(ra[1] == 1) 
	{
		swap(ra[1], ra[m]);
		fo(i,1,m) 
		{
			if(i==1) b[i] = ra[i]-1;
			else if(i==m) b[i] = ra[i]+1;
			else b[i] = ra[i];
		}
		b[m] = 2;
		fo(i,1,m) pf("%d ",ra[i]); pf("\n");
		pf("%d\n",m);
		fo(i,1,m) pf("%d ",b[i]);
		return 0;
	}
	fo(i,1,m) 
	{
		if(i==1) b[i] = ra[i]-1;
		else if(i==m) b[i] = ra[i]+1;
		else b[i] = ra[i];
	}
	if(ra[m] == 1) b[m] ++;
	fo(i,1,m) pf("%d ",ra[i]); pf("\n");
	pf("%d\n",m);
	fo(i,1,m) pf("%d ",b[i]);
	return 0;
}