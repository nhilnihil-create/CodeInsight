#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[100005];
int n;
int ans;
inline void read(int &x)
{
	int f;char c;
	for (f=1,c=getchar();c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for (x=0;c<='9'&&c>='0';c=getchar()) x=x*10+(c&15);x*=f;
}
inline int mn(int _x,int _y)
{
	return _x<_y?_x:_y;
}
inline int mx(int _x,int _y)
{
	return _x>_y?_x:_y;
}
inline int ab(int _x)
{
	if(_x<0) return -_x;
	else return _x;
}
inline bool cmp(int p,int q)
{
	return p<q;
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
		ans+=(a[i]==a[i-1]);
	if(ans&1) ans++;
	printf("%d\n",n-ans);
	return 0;
}

