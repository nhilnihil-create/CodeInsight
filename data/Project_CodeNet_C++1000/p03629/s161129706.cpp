#include<bits/stdc++.h>
#define vd void
typedef long long ll;
int gi(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[200010];
bool yes[26];
int len[200010];
int nxt[200010][26];
char ans[200010];
int main(){
	scanf("%s",S+1);int n=strlen(S+1);
	int nowlen=0,cnt=0;
	for(int i=n;i;--i){
		S[i]-='a';
		if(!yes[S[i]])yes[S[i]]=1,++cnt;
		if(cnt==26)++nowlen,cnt=0,memset(yes,0,sizeof yes);
		len[i]=nowlen;
	}
	for(int i=n-1;~i;--i){
		for(int j=0;j<26;++j)nxt[i][j]=nxt[i+1][j];
		nxt[i][S[i+1]]=i+1;
	}
	int m=0,p=0;
	for(int i=nowlen;i;--i){
		for(int j=0;j<26;++j)
			if(nxt[p][j]&&len[nxt[p][j]+1]<i){
				p=nxt[p][j],ans[++m]=S[p]+'a';
				break;
			}
	}
	for(int j=0;j<26;++j)
		if(!nxt[p][j]){
			ans[++m]=j+'a';
			break;
		}
	printf("%s",ans+1);
	return 0;
}
