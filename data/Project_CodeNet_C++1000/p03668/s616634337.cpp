#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define inf 1000000005
#define mod 1000000007
#define put putchar('\n')
using namespace std;
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}
int n,m,fa[N],sg[N],x,y;
int nedge,Next[N*2],head[N],to[N*2];
void add(int a,int b){
	Next[++nedge]=head[a];head[a]=nedge;to[nedge]=b;
}
#define V to[i]
void dfs(int x){
	for (int i=head[x];i;i=Next[i]){
		if (V!=fa[x]){
			fa[V]=x;
			dfs(V);
			sg[x]^=(sg[V]+1);
		}
	}
}
signed main(){
	n=read();
	for (int i=1;i<n;i++){
		x=read();y=read();add(x,y);add(y,x);
	}
	dfs(1);
	if (sg[1]==0) puts("Bob");
	else puts("Alice");
	return 0;
}