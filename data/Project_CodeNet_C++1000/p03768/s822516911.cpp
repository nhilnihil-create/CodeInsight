#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,m,q;
int a[N],b[N],c[N];
int Tag[N][11];
void push(int x,int y){
	for (int i=10;i>0;i--)
		Tag[y][i-1]=max(Tag[y][i-1],Tag[x][i]);
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++)
		a[i]=read(),b[i]=read();
	q=read();
	memset(Tag,0,sizeof Tag);
	for (int i=1;i<=q;i++){
		int v=read(),d=read();
		c[i]=read();
		Tag[v][d]=max(Tag[v][d],i);
	}
	for (int kk=10;kk--;)
		for (int i=1;i<=m;i++){
			push(a[i],b[i]);
			push(b[i],a[i]);
		}
	for (int i=1;i<=n;i++){
		int Max=0;
		for (int j=0;j<=10;j++)
			Max=max(Max,Tag[i][j]);
		cout << c[Max] << endl;
	}
	return 0;
}