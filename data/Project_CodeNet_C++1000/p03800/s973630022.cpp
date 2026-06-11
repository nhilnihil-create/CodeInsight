#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
char s[N];
int ans[N];
bool cl(){
	for(int i=3;i<=n;i++){
		if(s[i-1]=='o'&&ans[i-1]==1||s[i-1]=='x'&&ans[i-1]==0)ans[i]=ans[i-2];
		else ans[i]=(ans[i-2]^1);
	}
	bool flag1=0;
	if(s[n]=='o'&&ans[n]||s[n]=='x'&&ans[n]==0) flag1=(ans[1]==ans[n-1]);
	else flag1=(ans[1]==(ans[n-1]^1));
	bool flag2=0;
	if(s[1]=='o'&&ans[1]||s[1]=='x'&&ans[1]==0) flag2=(ans[2]==ans[n]);
	else flag2=(ans[2]==(ans[n]^1));
	return (flag1&&flag2);
}
int main()
{
	//freopen("H:\\c++1\\in.txt","r",stdin);
	//freopen("H:\\c++1\\out.txt","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	ans[1]=ans[2]=0;
	if(cl()){
		for(int i=1;i<=n;i++){
			if(ans[i])printf("S");else printf("W");
		}
		puts("");
		return 0;
	}
	ans[1]=1,ans[2]=0;
	if(cl()){
		for(int i=1;i<=n;i++){
			if(ans[i])printf("S");else printf("W");
		}
		puts("");
		return 0;
	}
	ans[1]=0,ans[2]=1;
	if(cl()){
		for(int i=1;i<=n;i++){
			if(ans[i])printf("S");else printf("W");
		}
		puts("");
		return 0;
	}
	ans[1]=1,ans[2]=1;
	if(cl()){
		for(int i=1;i<=n;i++){
			if(ans[i])printf("S");else printf("W");
		}
		puts("");
		return 0;
	}
	puts("-1");
	return 0;
}