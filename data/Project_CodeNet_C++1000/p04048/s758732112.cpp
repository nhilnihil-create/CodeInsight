#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#define ll long long
#define re register
#define file(a) freopen(a".in",,"r",stdin);freopen(a".out","w",stdout)
#define int ll
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return f*sum;
}
int n,x;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main(){
	n=gi();x=gi();
	printf("%lld\n",3*(n-gcd(n,x)));
	return 0;
}
