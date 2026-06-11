#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=2e5+5;
int n,nxt[MN][26],f[MN];
char S[MN];
int main(){
	scanf("%s",S+1);n=strlen(S+1);
	memset(nxt,-1,sizeof(nxt));
	for(reg int i=n;i;i--)
		for(reg int j=0;j<26;j++)
			nxt[i][j]=(S[i]==j+'a'?i:nxt[i+1][j]);
	memset(f,0x3f,sizeof(f));
	for(reg int i=n;i;i--){
		for(reg int j=0;j<26;j++){
			if(nxt[i][j]==-1){f[i]=1;break;}
			f[i]=min(f[i],f[nxt[i][j]+1]+1);
		}
	}
	reg int len=f[1],pos=1;
	while(len--){
		if(!len)for(reg int i=0;i<26;i++)
				if(nxt[pos][i]==-1)return 0*putchar(i+'a');
		for(reg int i=0;i<26;i++)
			if(f[pos]==f[nxt[pos][i]+1]+1){
				pos=nxt[pos][i]+1;
				putchar(i+'a');break;
			}
	}
	return 0;
}