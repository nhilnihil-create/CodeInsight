#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
#define db double
#define rg register int

using namespace std;

int n;
string s;
int a[500005];
int f[500005][26];
int t[500005];

inline int qr(){
	register char ch; register bool sign=0; rg res=0;
	while(!isdigit(ch=getchar()))if(ch=='-')sign=1;
	while(isdigit(ch))res=res*10+(ch^48),ch=getchar();
	if(sign)return -res; else return res;
}

inline int dfs(int i){
	if(i==0)return 0;
	if(t[i])return t[i];
	t[i]=1e9;
	for(rg j=0;j<26;++j){
		t[i]=min(t[i],dfs(f[i][j])+1);
	}return t[i];
}

int main(){
	cin>>s; n=s.size();
	for(rg i=1;i<=n;++i) a[i]=s[i-1]-'a';
	for(rg i=n-1;i>=1;--i){
		for(rg j=0;j<26;++j)
			f[i][j]=f[i+1][j];
		f[i][a[i+1]]=i+1;
	}
	for(rg j=0;j<26;++j)
		f[n+1][j]=f[1][j];
	f[n+1][a[1]]=1;
	dfs(n+1);
	rg i=n+1,v=t[n+1];
	while(i){
		for(rg j=0;j<26;++j){
			if(t[f[i][j]]==v-1){
				printf("%c",j+'a');
				i=f[i][j]; v=t[i];
				break;
			}
		}
	}puts("");
	return 0;
}
