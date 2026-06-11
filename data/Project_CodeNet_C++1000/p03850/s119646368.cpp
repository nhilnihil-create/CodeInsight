#include<bits/stdc++.h>
#define ci const int&
using namespace std;
int n,x[100010],tg;
char c[100010];
long long ans,s[100010],ss,ns;
void getc(char&x){
	x=getchar();
	while(x!='+'&&x!='-')x=getchar();
}
int main(){
	scanf("%d",&n),scanf("%d",&s[1]);
	for(int i=2;i<=n;++i)getc(c[i]),scanf("%d",&x[i]),s[i]=s[i-1]+(c[i]=='-'?-1:1)*x[i];
	ans=s[n];
	for(int i=n;i>=2;--i){
		ns+=x[i];
		if(c[i]=='-')ans=max(ans,s[i-1]+ss-ns),ss+=ns,ns=0;
	}
	printf("%lld",ans);
	return 0;
}