#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,x,y) for(int i=((int)x);i<=((int)y);i++)
#define Dep(i,y,x) for(int i=((int)y);i>=((int)x);i--)
#define Rep(i,x) for (int y,i=head[x];i;i=E[i].nxt)
using namespace std;

const int mod=1000000007;
const int inf=1000000009;

typedef double db;
typedef long long ll;
typedef vector<int> VI;
typedef unsigned int uint;
typedef pair<int,int> pii;

int rd() {
	char c=getchar(); int t=0,f=1;
	while (!isdigit(c)) f=(c=='-')?-1:1,c=getchar();
	while (isdigit(c)) t=t*10+c-48,c=getchar(); return t*f;
}
void wt(int x) {
	if (x<0) putchar('-'),wt(-x);
	else { if (x>9) wt(x/10); putchar(x%10+48); }
}

const int N=100015;
int n,x[N],len,fac[N],Ans=1,rest;

int main() {
	n=rd(),fac[0]=1;
	For (i,1,n) x[i]=rd();
	For (i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	
	len=1,rest=x[1]-1;
	For (i,2,n)
		if (x[i]-x[i-1]==1) {
			if (rest) rest--,len++;
			else Ans=1ll*Ans*(len+1)%mod,x[i]--;
		}
		else rest+=x[i]-x[i-1]-2,len++;
	
	Ans=1ll*Ans*fac[len]%mod;
	printf("%d\n",Ans);
	return 0;
}




