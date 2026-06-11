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
int n,m,h,w,i,j,flag;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();m=read();h=read();w=read();
   	if(n%h==0&&m%w==0)
   		printf("No\n");
   	else{
   		flag=(1000000000-1)/(h*w-1);
   		printf("Yes\n");
   		for(i=1;i<=n;i++,cout<<endl)
   			for(j=1;j<=m;j++)
   				if(i%h==0&&j%w==0)
   					pus(-flag*(h*w-1)-1,1);
   				else
   					pus(flag,1);
	}
    return 0;
}