#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
typedef pair<int,int> pii;
#define mp make_pair
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=100010,Inf=1e9+10;
int n,A[N];
int Solve(int b)
{
	int s=0,mn=Inf;
	for(int i=1;i<=n;i++)s+=A[i]&1,mn=min(mn,A[i]);
	if((n-s)&1)return b;if(s>1||mn==1)return b^1;
	int d=0;
	for(int i=1;i<=n;i++){if(A[i]&1)A[i]--;d=__gcd(A[i],d);}
	for(int i=1;i<=n;i++)A[i]/=d;
	return Solve(b^1);
}
int main()
{
	n=gi();
	for(int i=1;i<=n;i++)A[i]=gi();
	puts(Solve(1)?"First":"Second");
	return 0;
}
