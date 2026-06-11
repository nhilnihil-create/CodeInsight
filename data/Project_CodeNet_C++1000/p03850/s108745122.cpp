#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e+5+5;
const LL lim = 1e+15;

int n,a[N];
char op[N];
LL f[N][3];

LL maxll(LL x,LL y){return x>=y?x:y;}

int main(){
	n=get();
	a[1]=get();
	fo(i,2,n){
		char ch;
		while(ch=getchar(),ch!='+'&&ch!='-');
		op[i]=ch;
		a[i]=get();
	}
	fo(i,1,n)fo(j,0,2)f[i][j]=-lim;
	f[1][0]=a[1];
	fo(i,2,n)
	if (op[i]=='+'){
		f[i][0]=maxll(f[i-1][0],f[i-1][1])+a[i];
		f[i][1]=f[i-1][1]-a[i];
		f[i][2]=f[i-1][2]+a[i];
	}
	else{
		f[i][1]=f[i-1][0]-a[i];
		f[i][2]=maxll(f[i-1][1],f[i-1][2])+a[i];
	}
	LL ans=maxll(maxll(f[n][0],f[n][1]),f[n][2]);
	printf("%lld\n",ans);
	return 0;
}