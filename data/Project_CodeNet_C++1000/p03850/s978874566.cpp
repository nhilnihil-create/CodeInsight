#define NDEBUG
#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define xx first
#define yy second
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define lb(x) ((x)&(-(x)))
#define dalao 1000000007
#define inf 0x3f3f3f3f
#define N 100010
using namespace std;
typedef long long ll;
int n,a[N];
ll f[N][3];
char b[N];
inline int get(int i,int j){return (j&1)^(b[i]=='-')?-a[i]:a[i];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i==1)b[i]='+';
		else while((b[i]=getchar())!='+'&&b[i]!='-');
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n+1;i++)for(int j=0;j<3;j++)f[i][j]=-0x3f3f3f3f3f3f3f3fll;
	f[1][0]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)if(f[i][j]>-0x3f3f3f3f3f3f3f3fll){
		if(j<2&&b[i]=='-')f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+get(i,j));
		if(j)f[i+1][j-1]=max(f[i+1][j-1],f[i][j]+get(i,j));
		f[i+1][j]=max(f[i+1][j],f[i][j]+get(i,j));
//		cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
	}
	printf("%lld",f[n+1][0]);
	return 0;
}