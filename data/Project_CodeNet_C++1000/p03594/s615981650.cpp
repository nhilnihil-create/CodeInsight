#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define in(x,y) 1<=x&&x<=n&&1<=y&&y<=m
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char c[]={'R','Y','G','B'};
map<pair<int,int>,char> ch;
int main()
{	int n,m,d,t=0,X=0,Y=0; cin>>n>>m>>d;
	for(rint i=2;i<=n+m;i++,X++,Y=0)
	for(rint j=1-m;j<=n-1;j++,Y++)
	ch[mp(i,j)]=c[(X/d%2)*2+(Y/d%2)];
	for(rint i=1;i<=n;i++)
	for(rint j=1;j<=m;j++)
	{	int x=i+j,y=i-j;
		printf(j==m?"%c\n":"%c",ch[mp(x,y)]);
	}
	return 0;
}
