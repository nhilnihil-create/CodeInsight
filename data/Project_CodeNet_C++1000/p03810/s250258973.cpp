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
int n,i,a[100005];
int gcd(int u,int v){
	if(v==0) return u;
	return gcd(v,u%v);
}
int ss(int v){//0->先手必胜
	int sum=0,flag=0;
	for(i=1;i<=n;i++){
		sum+=a[i]-1;
		if(a[i]==1)
			flag=1;
	}
	if(flag==1){
		if(sum&1)
			return v;
		else
			return v^1;
	}
	sum=0;
	for(i=1;i<=n;i++)
		if((a[i]&1)==0)
			sum++;
	if(sum&1)
		return v;
	else if(n-sum>1)
		return v^1;
	for(i=1;i<=n;i++)
		if(a[i]&1){
			a[i]--;
			break;
		}
	flag=a[1];
	for(i=2;i<=n;i++)
		flag=gcd(flag,a[i]);
	for(i=1;i<=n;i++)
		a[i]/=flag;
	return ss(v^1);
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();
   	for(i=1;i<=n;i++)
   		a[i]=read();
   	if(ss(0)==0)
   		printf("First\n");
   	else
   		printf("Second\n");
    return 0;
}