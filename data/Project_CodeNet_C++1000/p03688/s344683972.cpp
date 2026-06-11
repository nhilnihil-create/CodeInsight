#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,up=-1,down=N;
int a[N],b[N],num[N];
template <typename T>
inline void read(T &x)
{
	T flg=1;x=0;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') flg=-flg;ch=getchar();}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=flg;
}
template <typename T>
inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline int max(const int& x,const int& y) {return x>y?x:y;}
inline int min(const int& x,const int& y) {return x<y?x:y;}
signed main()
{
	read(n);
	for(register int i=1;i<=n;++i)
	  {
	  	read(a[i]);
	  	++b[a[i]];
	  	up=max(up,a[i]);
	  	down=min(down,a[i]);
	  }
	if(up-down>1) {puts("No");return 0;}
	if(up-down==0)
	  {
		if(up<=n/2||up==n-1) {puts("Yes");return 0;}
		else {puts("No");return 0;}
	  }
	int col=up;
	if(col>=b[down]+1&&col<=b[down]+(n-b[down])/2) puts("Yes");
	else puts("No");
    return 0;
}