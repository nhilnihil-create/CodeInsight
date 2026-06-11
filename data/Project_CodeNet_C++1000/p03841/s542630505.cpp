#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[250010],p[510],s[510];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[p[i]=gi()]=i,s[i]=i;
	std::sort(s+1,s+n+1,[&](int a,int b){return p[a]<p[b];});
	int k=1;
	for(int _=1,i;_<=n;++_){
		i=s[_];
		for(int j=1;j<i;++j){
			while(k<p[i]&&a[k])++k;
			if(k==p[i])return puts("No"),0;
			a[k]=i;
		}
	}
	k=n*n;
	for(int _=n,i;_;--_){
		i=s[_];
		for(int j=i;j<n;++j){
			while(k>p[i]&&a[k])--k;
			if(k==p[i])return puts("No"),0;
			a[k]=i;
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;++i)printf("%d ",a[i]);
	return 0;
}
