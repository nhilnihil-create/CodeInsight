#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
#define inf 1000000000000000000LL
using namespace std;
int n, flag[N], w[N], nxt[N];
ll ans, now, s[N];
char S[10];
int main(){
	scanf("%d", &n); memset(flag, 0, sizeof(flag));
	for(int i=1; i<=n; i++){
		scanf("%d", &w[i]);
		if(i<=n-1){scanf("%s", S+1); if(S[1]=='-')flag[i+1]=1;}
	}
	s[0]=0; for(int i=1; i<=n; i++)s[i]=s[i-1]+w[i];
	now=n+1;
	for(int i=n; i; i--){nxt[i]=now; if(flag[i])now=i;}
	ans=inf; now=0;
	for(int i=1; i<=n; i++)if(flag[i]){
		ans=min(ans, now+s[nxt[i]-1]-s[i-1]);
		now+=w[i];
	}
	if(ans==inf)ans=0;
	printf("%lld", s[n]-ans*2);
	return 0;
}