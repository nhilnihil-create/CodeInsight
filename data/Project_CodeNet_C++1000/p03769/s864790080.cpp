#include<cstdio>
int main(){
	long long n,s,f[107];
	int p=1,a[107];
	scanf("%lld",&n);
	f[0]=1;
	for(;n;++p){
		s=0;
		int q=0;
		while(s+f[q]<=n&&q<p)s+=f[q++];
		for(int i=p;i>q;--i)a[i]=a[i-1],f[i]=f[i-1];
		a[q]=p,f[q]=s;
		n-=s;
	}
	printf("%d\n",p*2-2);
	for(int i=1;i<p;++i)printf("%d ",i);
	for(int i=1;i<p;++i)printf("%d ",a[i]);
	return 0;
}