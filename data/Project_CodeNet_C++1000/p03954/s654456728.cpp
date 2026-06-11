#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define dwn(i,x,y) for(register int i=(x);i>=(y);--i)
#define view(u,k) for(int k=fir[u];~k;k=nxt[k])
#define maxn 2000007
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x==0){putchar('0'),putchar('\n');return;}
    int f=0;char ch[20];
    if(x<0)putchar('-'),x=-x;
    while(x)ch[++f]=x%10+'0',x/=10;
    while(f)putchar(ch[f--]);
    putchar('\n');
    return;
}
int n,a[maxn],b[maxn],c[maxn],l=2147483647,r=0,ans=0;
int check(int x)
{
	rep(i,1,2*n-1)b[i]=(a[i]>=x)?1:0;
	c[1]=(b[1]==b[2])?1:0,c[2*n-1]=(b[2*n-1]==b[2*n-2])?1:0;
	rep(i,2,2*n-2){if(b[i]==b[i-1]||b[i]==b[i+1])c[i]=1;else c[i]=0;}
//	cout<<"b:";rep(i,1,2*n-1)cout<<b[i]<<" ";cout<<endl;
//	cout<<"c:";rep(i,1,2*n-1)cout<<c[i]<<" ";cout<<endl;
	if(c[n])return b[n];
	int L,R;L=R=n;
	while(!c[L]&&L>1)L--;while(!c[R]&&R<2*n-1)R++;
//	cout<<"L:"<<L<<" R:"<<R<<" CL:"<<c[L]<<" CR:"<<c[R]<<endl;
	if(c[L]&&c[R])
	{
		if(b[L]==b[R])return b[L];
		int pos=(n-L)<(R-n)?L:R;
		return b[pos];
	}
	else if(c[L]||c[R]){return (c[L]&b[L])|(c[R]&b[R]);}
	else return (n&1)^b[n]^1;
}
int main()
{
	//freopen("10.in","r",stdin);
    n=read();
    rep(i,1,2*n-1)a[i]=read(),l=min(a[i],l),r=max(a[i],r);
    while(l<=r)
    {
    	int mid=(l+r)/2,f=check(mid);
    //	cout<<"mid:"<<mid<<" f:"<<f<<endl;
    	if(f)ans=max(ans,mid),l=mid+1;
    	else r=mid-1;
    }
    write(ans);
	return 0;
}
/*
4
1 6 3 7 4 5 2
*/