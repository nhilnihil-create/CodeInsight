#include<stdio.h>
int d[100010];
inline int up(int x,int y){return x%y==0?x/y:x/y+1;}
inline int max(int a,int b){return a>b?a:b;}
int main(){
	int n,m,l,r,i,nex;
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d%d",&l,&r);
		d[1]++;
		d[r-l+2]--;
		for(i=r-l+2;i<=r;i=nex+1){
			nex=r/(r/i);
			d[max(up(l,r/i),r-l+2)]++;
			d[nex+1]--;
		}
	}
	for(i=1;i<=m;i++)d[i]+=d[i-1];
	for(i=1;i<=m;i++)printf("%d\n",d[i]);
}