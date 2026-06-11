#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int c[101];
void cxk(int i,int j){if(c[i]<j)puts("Impossible"),exit(0);}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),d=0,a;
	for(int i=1;i<=n;++i)++c[a=gi()],d=std::max(d,a);
	for(int i=d;i>=d+1>>1;--i)cxk(i,2-(i*2==d));
	for(int i=1;i<d+1>>1;++i)if(c[i])puts("Impossible"),exit(0);
	if(~d&1){if(c[d>>1]>1)puts("Impossible"),exit(0);}
	else{if(c[d+1>>1]>2)puts("Impossible"),exit(0);}
	puts("Possible");
	return 0;
}
