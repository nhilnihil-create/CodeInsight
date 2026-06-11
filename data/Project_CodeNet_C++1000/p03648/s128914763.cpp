/*
注意范围！
short范围：-32768~32767
unsigned short范围：0~65535
int范围：-2147483648~2147483647
uint范围：0~4294967295
INT范围：-9223372036854775808~9223372036854775807
UINT范围：0~18446744073709551615
float范围：-3.4e38～3.4e38，精度：6~7位
double范围：-1.7e308~1.7e308，精度：15~16位
ldouble范围：-1.2e4932~1.2e4932，精度：18~19位
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define ALL(a) (a).begin(),(a).end()
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(a) return puts(a),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;

INT k;
INT beit[55],xunhuan[55][55];

void init()
{
	memset(xunhuan[0],0,sizeof(xunhuan[0]));
	for(int i=0;i<50;i++)
		for(int j=0;j<50;j++)
		{
			if(j==i)
				xunhuan[i+1][j]=xunhuan[i][j]+50;
			else
				xunhuan[i+1][j]=xunhuan[i][j]-1;
		}
}

int main()
{
	init();
	cin>>k;
	INT d=49+(k/50);
	fill(beit,beit+50,d);
	INT a=k%50;
	for(int i=0;i<50;i++)
		beit[i]+=xunhuan[a][i];
	cout<<50<<endl;
	for(int i=0;i<50;i++)
		cout<<beit[i]<<(i==49?'\n':' ');
	return 0;
}
