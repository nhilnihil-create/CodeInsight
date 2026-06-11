#include <bits/stdc++.h>
const int N=200005;
char s[N];
int n,f[N],pos[N][26];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	f[n]=1;
	for (int i=0;i<26;i++) pos[n][i]=n;
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<26;j++) pos[i][j]=pos[i+1][j];
		pos[i][s[i]-'a']=i;
		f[i]=n;
		for (int j=0;j<26;j++) f[i]=std::min(f[i],f[pos[i][j]+1]+1);	
	} 
	int p=0;
	for (int i=f[0];i;i--){
		for (int j=0;j<26;j++)
			if (f[pos[p][j]+1]+1==i){
				putchar(j+'a');
				p=pos[p][j]+1;
				break;
			}
	}
} 