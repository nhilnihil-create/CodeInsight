#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
LL bin[42],n;
int a[205],js,len,k;
int main()
{
	bin[0]=1;for(RI i=1;i<=40;++i) bin[i]=bin[i-1]<<1LL;
	scanf("%lld",&n);++n;
	for(RI i=40;i>=0;--i) if(n&bin[i]) {k=i;break;}
	for(RI i=k-1;i>=0;--i) {
		++js;
		for(RI j=len;j>=len/2+1;--j) a[j+2]=a[j];
		a[len/2+2]=js;
		for(RI j=len/2;j>=1;--j) a[j+1]=a[j];
		a[1]=js,len+=2;
		if(n&bin[i]) {
			++js;
			for(RI j=len;j>=1;--j) a[j+1]=a[j];
			a[1]=a[len+2]=js,len+=2;
		}
	}
	printf("%d\n",len);
	for(RI i=1;i<=len;++i) printf("%d ",a[i]);
	puts("");
    return 0;
}