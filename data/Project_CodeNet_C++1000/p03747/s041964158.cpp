#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define ld double
#define inf 100001
#define mod 2147483647
#define INF (int)(1e9) 
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;

int n,L,T;

struct ant{
	int x,d;
}a[inf];

int to[inf];

int main(){
	rd(n) rd(L) rd(T)
	for (int i=1;i<=n;i++){
		rd(a[i].x) rd(a[i].d)
		if (a[i].d==2){
			a[i].d=-1;
		}
	}
	if (L==1){
		for (int i=1;i<=n;i++){
			printf("%d\n",0);
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		to[i]=((a[i].x+a[i].d*T)%L+L)%L;
	}
	int pos=0;
	for (int i=1;i<=n;i++){
		int tmp=a[i].x+a[i].d*T;
		if (tmp>0){
			pos=(pos+tmp/L)%n;
		}
		else if (tmp<0){
			pos=(pos+(tmp+1)/L-1)%n;
		}
	}
	pos=(pos+n)%n;
	sort(to+1,to+n+1);
	for (int i=pos+1;i<=n;i++){
		printf("%d\n",to[i]);
	}
	for (int i=1;i<=pos;i++){
		printf("%d\n",to[i]);
	}
	return 0;
}