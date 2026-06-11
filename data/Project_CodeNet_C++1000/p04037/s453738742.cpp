#include <bits/stdc++.h>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)
#define ror(a,b,c) for(register int a=c;a>=b;--a)

const int N=1e5+5;

int n,a[N];

inline bool judge(int x,int y){
	return y==a[x]||y>=a[x+1];
}

inline bool cmp(int a,int b) {return a>b;}

int main(){
	scanf("%d",&n); lor(i,1,n) scanf("%d",&a[i]); sort(a+1,a+1+n,cmp); a[0]=a[1];
	int x=0,y=0;
	while(x+1<=n&&y+1<=a[x+1]&&!judge(x+1,y+1)) ++x,++y;
	bool flag=false;
	int tar=a[x]; if(x+1<=n) tar=min(tar,a[x+1]);
	if(((tar-x)&1)==0) flag=true;
	int cnt=0; while(x+1<=n&&!judge(x+1,y)) ++x,++cnt; if(cnt&1) flag=true;
	puts(flag?"First":"Second");
	return 0;
}