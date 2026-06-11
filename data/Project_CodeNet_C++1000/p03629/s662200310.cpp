#include<cstdio>
const int N=200003,M=26;
char s[N];
int n,i,j,f[N],nxt[N][M],k,usd[N];
void init(){
	scanf("%s",s+1);
	while(s[n+1]){
		n++;
		usd[s[n]-97]=1;
	}
	for(j=0;j<M;j++)
		nxt[n+1][j]=n+1;
	for(i=n;i;i--){
		for(j=0;j<M;j++)
			nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-97]=i;
	}
}
int min(int x,int y){
	return x<y?x:y;
}
void work(){
	for(i=n+1;i;i--){
		f[i]=1<<30;
		for(j=0;j<M;j++)
			f[i]=min(f[i],f[nxt[i][j]+1]+1);
	}
	for(i=1;i<=n;){
		for(j=0;j<M;j++)
			if(f[i]==f[nxt[i][j]+1]+1)
			break;
		printf("%c",j+97);
		i=nxt[i][j]+1;
	}
}
int main(){
	init();
	work();
	return 0;
}