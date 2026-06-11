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
long long n,i,j,a[100005],b[100005],m,k,bz[100005][65],x;
double c[100005];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();
   	for(i=1;i<=n;i++)
		a[i]=read();
   	m=read();k=read();
   	for(i=1;i<n;i++)
   		bz[i][0]=i;
   	while(m--){
   		x=read();
   		swap(bz[x-1][0],bz[x][0]);
	}
	for(j=1;j<=59;j++)
		for(i=1;i<n;i++)
			bz[i][j]=bz[bz[i][j-1]][j-1];
	b[0]=a[1];
	c[0]=b[0];
	for(i=1;i<n;i++)
		a[i]=a[i+1]-a[i];
	for(i=1;i<n;i++){
		x=i;
		for(j=59;j>=0;j--)
			if((1LL<<j)&k)
				x=bz[x][j];
		b[i]=a[x];
	}
	for(i=1;i<n;i++){
		b[i]+=b[i-1];
		c[i]=b[i];
	}
	for(i=0;i<n;i++)
		printf("%.1lf\n",c[i]);
    return 0;
}