// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

char ans[10];
int getans(LL t)
{
	printf("? %lld\n",t);fflush(stdout);
	scanf("%s",ans);
	if(ans[0]=='Y')return 1;
	else return 0;
}
LL cur=0;
int getnxt(int cur)
{
	int l=(cur==0?0:-1),r=9,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(getans(1000000000ll*(mid+10ll*cur)+999999999))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	for(int i=1;i<=9;i++)cur=cur*10+getnxt(cur);
	while(cur%10==0)cur/=10;
	if(cur==1)
	{
		while(true)
		{
			if(getans(cur+1))break;
			cur*=10;
		}
		printf("! %lld\n",cur);
	}
	else
	{
		LL tmp=1;while(tmp<cur)tmp*=10;
		while(true)
		{
			if(getans(tmp)==0)break;
			tmp=tmp*10;
			cur=cur*10;
		}
		printf("! %lld\n",cur);
		fflush(stdout);
	}
	return 0;
}