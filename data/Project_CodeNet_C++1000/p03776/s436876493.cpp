#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll MAXN = 1001;
ll sum[MAXN],a[MAXN];
ll n,A,B;
ll dp[MAXN][MAXN];
map<ll,ll>ma;
void C(){
	dp[1][1] = 1;
	for(ll i = 0;i <= 151;i ++) dp[i][0] = 1;
	for(ll i = 2;i <= 151;i ++)
		for(ll j = 1;j <= 151;j ++)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]; 
}

bool cmp(ll a,ll b){
	return a > b;
}

void solve(){
	C();
	cin >> n >> A >> B;
	for(ll i = 1;i <= n;i ++)
		scanf("%lld",&a[i]),ma[a[i]] ++;
	sort(a + 1,a + n + 1,cmp);
	ll sum = 0;
	double pingjun = 0.0;
	for(ll i = 1;i <= A;i ++) sum += a[i];
	pingjun = (double)sum / (double)A;
	ll pos = 0;
	for(ll i = A;i >= 1;i --){
		if(a[i] != a[i - 1]){
			pos = i;
			break;
		}
	}
	ll ans = 0;
	if(pos == 1)
		for(int i = A;i <= B;i ++) ans += dp[ma[a[A]]][i];
	else ans = dp[ma[a[A]]][A - pos + 1];
	printf("%.8lf\n",pingjun);
	printf("%lld\n",ans);
	return;
}
int main(){
	solve();
	return 0;
}