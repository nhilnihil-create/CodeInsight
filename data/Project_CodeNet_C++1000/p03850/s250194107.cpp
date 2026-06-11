#include <bits/stdc++.h>

#define lld long long
#define pii pair<int,int>
#define pb push_back
#define next nextt
#define Inf 1000000000
#define Linf 1000000000000000000LL
#define Mod 1000000007

using namespace std;

int N; lld ans;
int op[100002],next[100002];
lld a[100002],sum[100002],sum2[100002];

int main(){
	scanf("%d",&N);
	scanf("%lld",&a[1]);
	sum[1] = a[1];
	for(int i=2; i<=N; i++){
		char s[3];
		scanf("%s",s);
		if(s[0]=='-') op[i] = -1;
		else op[i] =1;
		scanf("%lld",&a[i]);
		sum[i] = sum[i-1]+(a[i]*op[i]);
	}
	for(int i=N; i>=1; i--){
		sum2[i] = sum2[i+1]+a[i];
	}
	int tmp = N+1;
	for(int i=N; i>=2; i--){
		if(op[i] == -1){
			next[i] = tmp;
			tmp = i;
		}
	}
	ans = sum[N];
	for(int i=2; i<=N; i++){
		if(op[i] == 1) continue;
		ans = max(ans,sum[i-1]-(sum2[i]-sum2[next[i]])+sum2[next[i]]);
	}
	printf("%lld\n",ans);

	return 0;
}
