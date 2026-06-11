#include<cstdio>  
#include<iostream>  
#include<algorithm>  
#include<cstdlib>  
#include<cstring>
#include<string>
#include<climits>
#include<vector>
#include<cmath>
#include<map>
#define LL long long
#define pii pair<int,int>
#define mp make_pair
 
using namespace std;
 
inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
  return *p1++;
}
 
inline void read(int &x){
  char c=nc();int b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}
 
inline void read(LL &x){
  char c=nc();LL b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

inline int read(char *s)
{
	char c=nc();int len=1;
	for(;!(c>='a' && c<='z');c=nc()) if (c==EOF) return 0;
	for(;(c>='a' && c<='z');s[len++]=c,c=nc());
	s[len++]='\0';
	return len;
}

inline void read(char &x){
  for (x=nc();!(x>='A' && x<='Z');x=nc());
}

int wt,ss[19];
inline void print(int x){
	if (x<0) x=-x,putchar('-'); 
	if (!x) putchar(48); else {
	for (wt=0;x;ss[++wt]=x%10,x/=10);
	for (;wt;putchar(ss[wt]+48),wt--);}
}
inline void print(LL x){
	if (x<0) x=-x,putchar('-');
	if (!x) putchar(48); else {for (wt=0;x;ss[++wt]=x%10,x/=10);for (;wt;putchar(ss[wt]+48),wt--);}
}

int n,a[200010];

bool check1(int x)
{
	for (int i=1;i<2*n;i+=2)
		if (a[i]<x) return false;
	return true;
}

bool check(int x)
{
	if (check1(x)) return true;
	int y=0,z;
	for (int i=1;i<n;i++)
		if (a[i]>=x && a[i+1]>=x) y=i+1;
	z=y;
	if (z!=0)
	{
		while (a[z+2]>=x)
		{
			z+=2,y++;
			if (z+2>=2*n) break;
		}
		if (y>=n) return true;
	}
	y=0;
	for (int i=2*n-1;i>n;i--)
		if (a[i]>=x && a[i-1]>=x) y=i-1;
	z=y;
	if (z!=0)
	{
		while (a[z-2]>=x)
		{
			z-=2,y--;
			if (z-2<1) break;
		}
		if (y<=n) return true;
	}
	return false;
}

int main()
{
	read(n);
	memset(a,0,sizeof(a));
	for (int i=1;i<2*n;i++)
		read(a[i]);
	int l=2,r=2*n-2,mid,res;
	while (l<=r)
	{
		mid=l+r>>1;
		if (check(mid)) l=mid+1,res=mid;else r=mid-1;
	}
	print(res),puts("");
	return 0;
}
