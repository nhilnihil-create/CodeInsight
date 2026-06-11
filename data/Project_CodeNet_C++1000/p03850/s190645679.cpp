#include<bits/stdc++.h>
#define maxn 100005
#define LL long long
using namespace std;

int n;
LL sm[maxn],lsm[maxn];
bool isn[maxn];

int main(){
	scanf("%d",&n);
	LL ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&sm[i]);
		if(isn[i-1]) ans -= sm[i];
		else ans += sm[i];
		lsm[i] = ans;
		sm[i] += sm[i-1];
		char ch[2];
		if(i<n){
			scanf("%s",ch);
			if(ch[0] == '-')isn[i] = 1;
		}
	}
	int nx = n;
	for(int i=n-1;i>=0;i--) if(isn[i]){
		ans = max(ans , sm[n] - sm[nx] - (sm[nx] - sm[i]) + lsm[i]);
		nx = i;
	}
	printf("%lld\n",ans);
}