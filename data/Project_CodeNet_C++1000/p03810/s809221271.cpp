#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,A[100010];
bool fuck(){
	int c[2]={0},c1=0;
	for(int i=1;i<=n;++i)++c[A[i]&1],c1+=A[i]==1;
	if(c1||(c[0]&1))return c[0]&1;
	if(c[1]>1&&~c[0]&1)return 0;
	int g=0;
	for(int i=1;i<=n;++i){
		if(A[i]&1)--A[i];
		g=std::__gcd(g,A[i]);
	}
	for(int i=1;i<=n;++i)A[i]/=g;
	return!fuck();
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)A[i]=gi();
	if(fuck())puts("First");
	else puts("Second");
	return 0;
}
