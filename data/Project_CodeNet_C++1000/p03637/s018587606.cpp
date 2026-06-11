#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n,a[N],s0,s1,s2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t=0;
		scanf("%d",&a[i]);
		while(a[i]%2==0&&t<2) a[i]>>=1,t++;
		if(!t) s0++;
		else  if(t==1) s1++;
		else s2++;
	}
	if(s2>=s0||s2>=n/2) puts("Yes");
	else puts("No");
	return 0;
}
