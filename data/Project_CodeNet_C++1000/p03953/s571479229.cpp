#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
#define el putchar('\n')
#define ta putchar('	')
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
//	sprintf(str,"%s.out",s);
//	freopen(str,"w",stdout);
	#endif
}
inline ll rd()
{
	static ll x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
int n,a[N],p[N],f[N];
ll b[N];
bool vis[N];

int main()
{
	n=rd();
	fo(i,1,n){
		a[i]=rd();
		b[i]=a[i]-a[i-1];
		f[i]=p[i]=i;
	}
	int m=rd();ll K=rd();
	fo(i,1,m){
		int x=rd();
		swap(p[x],p[x+1]);
	}
	fo(x,2,n)if(!vis[x]){
		int u=x;
		static vector<int>vec;
		vec.clear();
		for(;!vis[u];u=p[u])vec.push_back(u),vis[u]=1;
		int siz=vec.size();
		fo(i,0,siz-1)f[vec[i]]=vec[(i+K%siz)%siz];
	}
	ll hh=0;
	fo(i,1,n)printf("%lld.0\n",hh+=b[f[i]]);
	return 0;
}
