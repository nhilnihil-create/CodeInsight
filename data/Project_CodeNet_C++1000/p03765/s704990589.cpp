#include<cstdio>
#include<cstring>
char S[100100],T[100100];
int x1,x2,y1,y2,Q,n,m,a[100100],b[100100];
int main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=1;i<=n;i++)
		a[i]=(a[i-1]+(S[i]-'A'+1))%3;
	scanf("%s",T+1);
	m=strlen(T+1);
	for(int i=1;i<=m;i++)
		b[i]=(b[i-1]+(T[i]-'A'+1))%3;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		if((a[x2]-a[x1-1]-b[y2]+b[y1-1])%3==0)puts("YES");
		else puts("NO");
	}
	return 0;
}