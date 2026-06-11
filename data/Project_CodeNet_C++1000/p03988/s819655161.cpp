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
long long n,m,i,a[105],l;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();
   	for(i=1;i<=n;i++)
   		a[i]=read();
   	sort(a+1,a+n+1);
   	for(i=1;i<n;i++)
   		if(a[i]+1<a[i+1]){
			printf("Impossible\n");
			return 0;
		}
   	l=a[n];
   	a[0]=-1;
   	if(l&1){
   		if(a[1]!=(l+1>>1)||a[2]==a[3]){
   			printf("Impossible\n");
   			return 0;
   		}
   		for(i=1;i<=n;i++)
   			if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
   				printf("Impossible\n");	
   				return 0;
   			}
   		printf("Possible\n");
   	}
   	else{
   		if(a[1]!=(l>>1)||a[1]==a[2]){
   			printf("Impossible\n");
   			return 0;
   		}
		for(i=2;i<=n;i++)
			if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
   				printf("Impossible\n");	
   				return 0;
   			}
   		printf("Possible\n");
	}
    return 0;
}