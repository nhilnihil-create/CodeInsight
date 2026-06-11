#include<bits/stdc++.h>
#define mo 1000000007
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
long long n,l,t,i,x[100005],d[100005],cnt,sum;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();l=read();t=read();
   	for(i=1;i<=n;i++){
   		x[i]=read();
   		d[i]=read();
   		if(d[i]==2)
   			d[i]=-1;
   	}
   	for(i=1;i<=n;i++){
   		sum=x[i]+d[i]*t;
   		if(sum>=0)
   			cnt=(cnt+sum/l)%n;
   		else
   			cnt=(cnt+(sum+1)/l-1+n)%n;
   		x[i]=(sum%l+l)%l;
	}
	sort(x+1,x+n+1);
	for(i=cnt+1;i<=n;i++)
		pus(x[i],2);
	for(i=1;i<=cnt;i++)
		pus(x[i],2);
    return 0;
}