//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <time.h>
using namespace std;
long double esp=1e-11;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define cle(a) while(!a.empty())a.pop()
#define mem(p,c) memset(p,c,sizeof(p))
#define mp(A, B) make_pair(A, B)
#define pb push_back
typedef long long int LL;
const long double PI = acos((long double)-1);
const LL INF=0x3f3f3f3f3f3f3f3fll;
const int MOD =1000000007ll;
const int maxn=100100;
char s[100];
char g[100];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("in1.txt", "w", stdout);
    //::iterator iter;                  %I64d
    //for(int x=1;x<=n;x++)
    //for(int y=1;y<=n;y++)
    //scanf("%d",&a);
    //printf("%d\n",ans);
    printf("? 1000000000000\n");
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='Y')
	{
		LL ans=1;
		LL tem=9;
		for(int x=1;x<=10;x++)
		{
			printf("? %lld\n",tem);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')
				break;
			ans*=10;
			tem=tem*10+9;
		}
		printf("! %lld\n",ans);
		fflush(stdout);
		return 0;
	}
	else
	{
		g[0]='1';
		for(int x=1;x<=10;x++)
		{
			g[x]='0';
			printf("? %s\n",g);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='N')
			{
				g[x]='\0';
				break;
			}
		}
		int len=strlen(g);
		if(len==1)
		{
			for(int x=1;x<=9;x++)
			{
				printf("? %d\n",x*10);
				fflush(stdout);
				scanf("%s",s);
				if(s[0]=='Y')
				{
					printf("! %d\n",x);
					fflush(stdout);
					return 0;
				}
			}
		}
		for(int x=0;x<=len-2;x++)
		{
			int l,r;
			if(x==0)l=1;
			else l=0;
			r=9;
			while(l<r)
			{
				int m=(l+r+1)/2;
				g[x]=m+'0';
				string ss(g,g+x+1);
				printf("? %s\n",ss.c_str());
				fflush(stdout);
				scanf("%s",s);
				if(s[0]=='Y')l=m;
				else r=m-1;
			}
			g[x]=l+'0';
		}
		g[len]='9';
		for(int x=0;x<=9;x++)
		{
			g[len-1]='0'+x;
			string ss(g,g+len+1);
			printf("? %s\n",ss.c_str());
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')
			{
				string ss(g,g+len);
				printf("! %s\n",ss.c_str());
				fflush(stdout);
				return 0;
			}
		}
	}
	return 0;
}
