#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 5010
#define MOD 1000000007
#define int ll
int N,M;
string S;

int num[maxn][maxn];
int dp[maxn][maxn];

int power(int a,int b,int M){ //returns a^b % M, O(logb)
  	 if (b==0) return 1;
    
   	int half = b/2;
   	int halfval;
    
   	halfval = (power(a,half,M))%M;
   	if (b%2 == 0) return (halfval * halfval) % M;
   	else return (((halfval * halfval) % M) * (a % M)) % M;
}

int modinv(int a,int b){
	return (a * power(b,MOD-2,MOD)) % MOD;
}
int dpf(int i,int j){
	if (dp[i][j] != -1) return dp[i][j];

	if (i == 0 && j == 0) return dp[i][j] = 1;
	if (i < j) return dp[i][j] = 0;
	
	dp[i][j] = dpf(i-1,j+1) + dpf(i-1,j+1);
	dp[i][j] %= MOD;
	
	dp[i][j] += dpf(i-1,max((ll)0,j-1));
	
	dp[i][j] %= MOD;
	
	return dp[i][j];
}

int32_t main(){
	fast;
	
	cin>>N>>S;
	
	M = S.size();
	mem(dp,-1);
	
	

	

	cout<<dpf(N,M);
	
	
	
	
	
}

