#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,j,now,nt[200010][26],f[200010];
char s[200010];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[n+1]=1;f[n+2]=0;
	for(i=0;i<26;i++)nt[n+1][i]=n+1;
	for(i=n;i;i--){
		for(j=0;j<26;j++)nt[i][j]=nt[i+1][j];
		nt[i][s[i]-'a']=i;
		f[i]=n+1;
		for(j=0;j<26;j++)f[i]=min(f[i],f[nt[i][j]+1]+1);
		//printf("%d %d\n",i,f[i]);
	}
	now=f[1];i=1;
	while(now--){
		for(j=0;j<26;j++)if(f[nt[i][j]+1]+1==f[i]){
			printf("%c",j+'a');i=nt[i][j]+1;break;
		}
	}
}