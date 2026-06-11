#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const double eps=1e-6;
const LL P=1e9+7;
const int N=500050;
int n,m;
int a[100000+10];
int tp=0;
int b[100000+10];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) scanf("%d",&a[i]);
    for(int i=1;i<=m;++i){
    	if(a[i]%2==0) continue;
    	if(i==1||i==m) continue;
    	if(a[1]%2==0){
    		swap(a[1],a[i]);
    		continue;
		}
		if(a[m]%2==0){
			swap(a[m],a[i]);
			continue;
		}
		puts("Impossible");return 0;
	}
	if(m==1){
		b[++tp]=1;
		if(a[1]>1)b[++tp]=a[1]-1;
	}
	else{
		b[++tp]=a[1]+1;
		for(int i=2;i<m;++i) b[++tp]=a[i];
		if(a[m]>1) b[++tp]=a[m]-1;
	}
	for(int i=1;i<=m;++i) printf("%d ",a[i]);puts("");
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i) printf("%d ",b[i]);
	puts("");
	return 0;
}
/*
5
1 2 2
1 2 2
*/