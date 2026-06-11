#include <bits/stdc++.h>
using namespace std;

#define rep(i,N) repf(i,0,N)
#define reps(i,N) repfs(i,0,N)
#define repf(i,a,b) for(int i=a;i<b;i++)
#define repfs(i,a,b) for(int i=a+1;i<=b;i++)
#define repr(i,N) for(int i=N-1;i>=0;i--)
#define reprs(i,N) for(int i=N;i>0;i--)

#define d(a) if(isDebugMode) cout<<#a<<"="<<a<<","
#define d2(a,b) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b
#define d3(a,b,c) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c
#define d4(a,b,c,d) if(isDebugMode) cout<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<","<<#d<<"="<<d
#define da(arr,N){if(isDebugMode){rep(i,N){if(arr[i]==INF)printf("INF ");else cout<<arr[i]<<" ";} cout<<endl;}}
#define da2(arr,N,M){if(isDebugMode)rep(i,N){rep(j,M){if(arr[i][j]==INF)printf(" INF");else printf(" %3d",arr[i][j]);}cout<<endl;}}
#define pb push_back
#define pob pop_back

auto chmax =[](int &a,int b){ a = max(a, b);};
auto chmin =[](int &a,int b){ a = min(a, b);};

typedef long long ll;
typedef pair<int,int> P;
const int INF = 100000000;
const int MOD = 1000000007;
const int dx[4] = { 0, 1, 0,-1};
const int dy[4] = { 1, 0,-1, 0};

bool isDebugMode=1;
//--------------------------------------//
int h,w,a,b;

vector<ll> v;

#define MAX 200000
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve(){
	COMinit();
	rep(i,h-a){
		v.pb(COM(b-1+i,i));
	}
	ll ans=0;
	rep(i,h-a){
		ans+=(v[i]*COM(h-i-1+w-b-1,w-b-1))%MOD;
	}
	ans%=MOD;
	cout<<ans<<endl;
}

int main(){
	cin>>h>>w>>a>>b;
	solve();
	return 0;
}
