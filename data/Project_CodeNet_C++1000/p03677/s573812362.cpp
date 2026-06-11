#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898 
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
long long n,m,i,a[100005],cf[100005],cf2[100005],ans,max1;
void cr(long long x,long long y,long long z){
	if(x>y)
		return;
	cf[x]+=z;
	cf[y+1]-=z;
	cf2[x+1]++;
	cf2[y+1]--;
	cf[y+1]-=y-x;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();m=read();
   	for(i=1;i<=n;i++)
		a[i]=read();
	for(i=1;i<n;i++){
		if(a[i]<a[i+1]){
			cr(a[i]+1,a[i+1],0);
			ans+=a[i+1]-a[i];
		}
		else{
			cr(a[i]+1,m,0);
			cr(1,a[i+1],m-a[i]);
			ans+=a[i+1]-a[i]+m;
		}
	}
	for(i=1;i<=m;i++){
		cf2[i]+=cf2[i-1];
		cf[i]+=cf2[i]+cf[i-1];
		max1=max(max1,cf[i]);
	}
	ans-=max1;
	pus(ans,2);
    return 0;
}