#include<bits/stdc++.h>
using namespace std;
#define il inline
#define gc getchar()
#define ri register int
#define rb register bool
#define rc register char
#define rp(i,x,y) for(ri i=x;i<=y;++i)
#define my(i,x,y) for(ri i=x;i>=y;--i)

const int N=5e5+10,inf=1e9;
int len,pre[N];
struct node{int to[26];node(){memset(to,0,sizeof(to));}}nod[N];
bool vis[N];
char str[N];
vector<int>V[26];

il int read()
{
	rc ch=gc;ri x=0;rb y=1;
	while(ch!='-' && (ch>'9' || ch<'0'))ch=gc;
	if(ch=='-')ch=gc,y=0;
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
	return y?x:-x;
}
void print(ri x){if(!x)return;print(pre[x]);printf("%c",str[x]);}
il int upp(ri x,ri y)
{
	ri l=0,r=V[x].size()-1;
	while(l<r){ri mid=(l+r)>>1;if(V[x][mid]>y)r=mid;else l=mid+1;}
	return l;
}

int main()
{
	//freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	scanf("%s",str+1);len=strlen(str+1);
	rp(i,1,len)V[str[i]-'a'].push_back(i);rp(i,0,25)V[i].push_back(inf);
	rp(i,1,len)
	{
		rp(j,0,25){ri to=upp(j,i);if(V[j][to]!=inf)nod[i].to[j]=V[j][to];}
	}
	rp(i,0,25)if(V[i][0]!=inf)nod[0].to[i]=V[i][0];
	//QwQ
	//rp(i,1,len)rp(j,0,25)printf("nod[%d].to[%d]=%d\n",i,j,nod[i].to[j]);
	//QwQ
	queue<int>Q;
	rp(i,0,25)if(nod[0].to[i])Q.push(nod[0].to[i]),vis[nod[0].to[i]]=1;else return printf("%c",(char)('a'+i)),0;
	while(!Q.empty())
	{
		ri nw=Q.front();Q.pop();
		rp(i,0,25)
		{ri t=nod[nw].to[i];if(t){if(!vis[t])vis[t]=1,pre[t]=nw,Q.push(t);}else return print(nw),printf("%c",(char)('a'+i)),0;}
	}
	return 0;
}
