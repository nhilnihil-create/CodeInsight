#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,x,y,f[500010],hed[500010],too[500010],nxt[500010],nedge;
void ae(int x,int y){
	nxt[++nedge]=hed[x];
	hed[x]=nedge;
	too[nedge]=y;
}
void dfs(int x,int l){
	for (int i=hed[x];i;i=nxt[i]){
		int y=too[i];
		if (y==l) continue;
		dfs(y,x);
		f[x]^=f[y]+1;
	}
}
int main(){
	cin>>n;
	FOR(i,2,n){
		getint(x),getint(y);
		ae(x,y),ae(y,x);
	}
	dfs(1,0);
	puts(f[1]?"Alice":"Bob");
	return 0;
}
