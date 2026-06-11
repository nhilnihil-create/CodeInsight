#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,j,k)  for(register int i=(int)(j);i<=(int)(k);i++)
#define rrep(i,j,k) for(register int i=(int)(j);i>=(int)(k);i--)

ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

const int maxn=100100;
int n;
int a[maxn];

int main(){
	n=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	rep(i,1,n+1){
		if(a[i]<i){
			i--;
			int num=0;
			for(int j=i+1;j<=n;j++)
				if(a[j]==i) num++;
			if(num&1){
				puts("First");
				return 0;
			}
			if((a[i]-i)&1) puts("First");
			else puts("Second");
			return 0;
		}
	}
}
