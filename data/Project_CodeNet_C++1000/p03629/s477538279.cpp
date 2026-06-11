#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,j,now,nt[240001][26],f[500001];
char s[500001];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(f,44,sizeof(f));
	f[n+1]=1;f[n+2]=0;
	for(i=0;i<26;i++)nt[n+1][i]=n+1;
	for(i=n;i;i--){
		for(j=0;j<26;j++)nt[i][j]=nt[i+1][j];
		nt[i][s[i]-'a']=i;
	}
	for(i=n;i;i--)
	 for(j=0;j<26;j++)f[i]=min(f[i],f[nt[i][j]+1]+1);
	now=1;
	for(j=f[1];j;j--)
	 for(i=0;i<26;i++)if(f[now]==f[nt[now][i]+1]+1){
	 	printf("%c",i+'a');
	 	now=nt[now][i]+1;
	 	break;
	 }
}