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
long long n,i,f[1000005],sum[1000005],ans;
int main(){
	f[0]=1;
	sum[0]=1;
   	f[1]=1;
   	sum[1]=2;
   	n=read();
   	for(i=2;i<=n;i++){
   		f[i]=(sum[i-1]-f[i-2]+mo)%mo;
   		sum[i]=(sum[i-1]+f[i])%mo;
   	}
   	for(i=0;i<=n;i++){
		if(i<=n-2)
			ans=(ans+f[i]*(n-1)%mo*(n-1))%mo;
		if(i==n)
			ans=(ans+f[i])%mo;
		else
			ans=(ans+f[i]*min(i+1,n-1))%mo;
	}
	pus(ans,2);
    return 0;
}