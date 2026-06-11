#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 505
struct Node
{
	int id,pl;
};
Node a[N];
int ans[N*N],n,l,r;
bool cmp(Node x,Node y){return x.pl<y.pl;}
bool spj()
{
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=a[i].pl;j++) if(ans[j]==a[i].id) cnt++;
		if(cnt!=a[i].id) return 0;
	}
	return 1;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i].id=i,a[i].pl=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) ans[a[i].pl]=a[i].id;
	l=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=a[i].id;j++)
		{
			while(ans[l]) l++;
			ans[l++]=a[i].id;
		}
	}
	r=n*n;
	for(int i=n;i>=1;i--)
	{
		for(int j=a[i].id+1;j<=n;j++)
		{
			while(ans[r]) r--;
			ans[r--]=a[i].id;
		}
	}
	// for(int i=1;i<=n*n;i++) printf("%d ",ans[i]); cout<<"\n";
	if(!spj()) {cout<<"No\n"; return 0;}
	cout<<"Yes\n";
	for(int i=1;i<=n*n;i++) printf("%d ",ans[i]); cout<<"\n";
	return 0;
}


