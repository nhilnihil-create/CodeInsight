#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,lst[N][30],f[N];
vector<int> ans;
char s[N];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	reverse(s+1,s+n+1);
	f[0]=1;
	for (int i=1;i<=n;++i){
		for (int j=0;j<26;++j) lst[i][j]=lst[i-1][j];
		lst[i][s[i]-'a']=i;
		f[i]=i+1;
		for (int j=0;j<26;++j){
			if (!lst[i][j]) f[i]=1;
			else f[i]=min(f[i],f[lst[i][j]-1]+1);
		}
	}
	for (int i=n;i>=0;--i){
		for (int j=0;j<26;++j){
			if (!lst[i][j]||f[i]==f[lst[i][j]-1]+1){
				ans.push_back(j);
				i=lst[i][j];
				break;
			}
		}
	}
	for (int i:ans) putchar(i+'a'); puts("");
	return 0;
}