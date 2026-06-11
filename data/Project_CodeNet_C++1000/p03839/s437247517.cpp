#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
int n, k, a;
ll p[MX], al[MX],ans;

int main(){
	scanf("%d%d", &n, &k);
	rep(i,n){
		scanf("%d", &a);
		p[i+1] = p[i] + (a>0?a:0);
		al[i+1] = al[i] + a;
	}
	rep(i,n-k+1) ans = max(ans,p[i]+p[n]-p[i+k]+max(0ll,al[i+k]-al[i]));
	printf("%lld\n", ans);
}