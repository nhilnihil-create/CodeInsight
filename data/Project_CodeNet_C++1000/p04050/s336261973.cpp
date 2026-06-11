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
int n,m,i,j,a[105],sum;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();m=read();
   	for(i=1;i<=m;i++){
   		a[i]=read();
   		if(a[i]&1)
   			sum++;
   	}
   	if(n==1){
   		pus(1,2);
   		pus(1,2);
   		pus(1,2);
   		return 0;
   	}
   	if(sum>=3){
   		printf("Impossible\n");
		return 0;
	}
	if(m==1){
		pus(a[1],2);
		pus(2,2);
		pus(1,1);
		pus(a[1]-1,2);
		return 0;
	}
	for(i=1;i<=m;i++)
		if(a[i]&1){
			if(a[1]&1)
				swap(a[i],a[m]);
			else
				swap(a[1],a[i]);
		}
	for(i=1;i<=m;i++)
		pus(a[i],1);
	cout<<endl;
	if(a[1]==1)
		n=2;
	else
		n=1;
	a[1]--;
	a[m]++;
	pus(m-n+1,2);
	for(i=n;i<=m;i++)
		pus(a[i],1);
	cout<<endl;
    return 0;
}