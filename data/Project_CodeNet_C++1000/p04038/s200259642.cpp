#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,k,i,j,jc[4000005],ny[4000005],f[2005];
long long ksm(long long u,long long v){
	long long o=1;
	while(v){
		if(v&1)
			o=o*u%mo;
		u=u*u%mo;
		v>>=1;
	}	
	return o;
}
long long C(long long u,long long v){
	return jc[u]*ny[v]%mo*ny[u-v]%mo;
}
int main(){
	n=read();k=read();
	if(k==1){
		pus(1,2);
		return 0;
	}
	jc[0]=1;
	for(i=1;i<=n*k;i++)
		jc[i]=jc[i-1]*i%mo;
	ny[n*k]=ksm(jc[n*k],mo-2);
	for(i=n*k-1;i>=0;i--)
		ny[i]=ny[i+1]*(i+1)%mo;
	f[0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			f[j]=(f[j]+f[j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2))%mo;
	pus(f[n]*jc[n]%mo,2);
    return 0;
}