#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int N=2e5+5;
char s[N];
int h,t,n;
int tmp[30], nxt[N][30], q[N], pre[N];
void print(int now){
	if (!now) return;
	print(pre[now]);
	putchar(s[now]);
}
void Bfs(){
	memset(pre,-1,sizeof pre);
	h=1,t=0;
	q[++t]=0; pre[0]=0;
	while (h<=t){
		int x=q[h++];
//		if (x==n+1) return (void)(print(pre[x]));
		for (int i=0,y;i<26;i++){
			y=nxt[x][i];
			if (y==n+1) {
				print(x);
				putchar('a'+i);
				return;
			}
			if (pre[y]==-1) pre[y]=x, q[++t]=y;
		}
	}
}
int main(){
	fread(s+1,1,200003,stdin);
	n=strlen(s+1);
	for (int i=0;i<26;i++) tmp[i]=n+1;
	for (int i=n;i>=0;i--){
		for (int j=0;j<26;j++) nxt[i][j]=tmp[j];
		tmp[s[i]-'a']=i;
	}
	Bfs();
	return 0;
}