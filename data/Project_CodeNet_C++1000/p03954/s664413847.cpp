/************************************************
*Author        :  xzj213
*Created Time  :  2019.11.07.08:33
*Mail          :  xzj213@qq.com
*Problem       :  pyramid
************************************************/
#include <bits/stdc++.h>
#define REP(i,a,b) for(register int i=(a);i<=(b);i++)
#define DREP(i,a,b) for(register int i=(a);i>=(b);i--)
#define mem(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define lson k<<1
#define rson k<<1|1
#define x first
#define y second
#define str(a) strlen(a)
#define max_(x,y) ((x)>(y)?(x):(y))
#define min_(x,y) ((x)<(y)?(x):(y))
#define lowbit(i) ((x)&-(x))
using namespace std;
const int maxn=1e6+5;
int n,a[maxn*2],b[maxn*2];
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>57 || ch<48){if(ch==45)f=-1;ch=getchar();}
    while(ch<=57 && ch>=48){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
bool check(int Mid){
	REP(i,1,n*2-1)b[i]=(a[i]>Mid?1:0);
	REP(i,0,n-2){
		if(b[n-i]==b[n-i-1])
			return b[n-i];
		if(b[n+i]==b[n+i+1])
			return b[n+i];
	}
	return b[1];
}
int main() {
    n=read();
	REP(i,1,n*2-1)a[i]=read();
	int l=1,r=n*2-1;
	while(l<=r){
		int Mid=(l+r)>>1;
		if(check(Mid))l=Mid+1;
		else r=Mid-1;
	}
	cout<<r+1<<endl;
    return 0;
}
