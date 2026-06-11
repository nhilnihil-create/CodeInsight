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

const int N = 1e+6+5;
const int mo = 1e+9+7;


int f[N],pre[N];
int n;

int add(int x,int y){return x+y>=mo?x+y-mo:x+y;}

int main(){
	n=get();
	f[0]=1;
	pre[0]=1;
	fo(i,1,n){
		if (i>=3)f[i]=pre[i-3];
		f[i]=add(f[i],f[i-1]);
		pre[i]=add(pre[i-1],f[i]);
	}
	LL ans=(1ll*f[n]+1ll*f[n-1]*(n-1)%mo)%mo;
	fo(i,0,n-2)ans=(ans+1ll*f[i]*(n-1)%mo*(n-1)%mo)%mo;
	fo(i,0,n-2)ans=(ans+1ll*f[i]*(i+1)%mo)%mo;
	printf("%lld\n",ans);
	return 0;
}