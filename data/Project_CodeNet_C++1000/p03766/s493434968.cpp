#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e6+19;
const int p=1e9+7;

int f[N],g[N];
int n;

int main(){
	n=IN();
	f[1]=g[1]=n;
	For(i,2,n+1){
		f[i]=(f[i-1]+1ll*(n-1)*(n-1))%p;
		if (i-3>0) f[i]=(f[i]+g[i-3])%p;
		f[i]=(0ll+f[i]+min(i-3,0)-(i-n-1)+1)%p;
		g[i]=(g[i-1]+f[i])%p;
	}
	printf("%d\n",f[n]);
}