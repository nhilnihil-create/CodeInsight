#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int n,m,q,color[MAXN],h[MAXN],nx[MAXN<<1],to[MAXN<<1],tot;
int v[MAXN],d[MAXN],c[MAXN],mxd[MAXN];
void link(int x,int y){to[++tot]=y;nx[tot]=h[x];h[x]=tot;}
void lk(int x,int y){link(x,y);link(y,x);}
int queue1[MAXN],queue2[MAXN],l,r;
void bfs(int x,int y,int z){
	l=r=1;
	queue1[r]=x;
	queue2[r]=y;
	while(l<=r){
		int cx=queue1[l],cy=queue2[l];
		l++;
		if(mxd[cx]>=cy)continue;
		mxd[cx]=cy;
		if(!color[cx])color[cx]=z;
		for(int i=h[cx];i;i=nx[i]){
			if(mxd[to[i]]<cy-1){
				queue1[++r]=to[i];
				queue2[r]=cy-1;
			}	
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		mxd[i]=-1;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		lk(a,b);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>v[i]>>d[i]>>c[i];	
	}
	for(int i=q;i>=1;i--){
		bfs(v[i],d[i],c[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<color[i]<<"\n";
	}
	return 0;
}