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
void sw(int *f){
	int ff=f[3];
	f[3]=f[2];
	f[2]=f[1];
	f[1]=f[0];
	f[0]=ff;
}
int n,m,i,j,k,a[305][305],book[305],sum[305],max1,max2,ans;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();m=read();
   	for(i=1;i<=n;i++)
   		for(j=1;j<=m;j++)
    		a[i][j]=read();
    ans=1000000;
    for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			for(k=1;k<=m;k++)
				if(book[a[j][k]]==0){
					sum[a[j][k]]++;
					break;
				}
		max1=0;
		for(j=1;j<=m;j++)
			if(sum[j]>max1){
				max1=sum[j];
				max2=j;
			}
		book[max2]=1;
		ans=min(ans,max1);
		for(j=1;j<=m;j++)
			sum[j]=0;
	}
	pus(ans,2);
    return 0;
}