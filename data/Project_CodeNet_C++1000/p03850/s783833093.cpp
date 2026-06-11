#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll dp[MAXN][3];
char op[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>A[1];
	for (int i=2; i<=n; i++) cin>>op[i-1]>>A[i];
	
	dp[1][0]=A[1];
	dp[1][1]=dp[1][2]=-INF;
	for (int i=2; i<=n; i++){
		if (op[i-1]=='+'){
			dp[i][0]=max({dp[i-1][0], dp[i-1][1], dp[i-1][2]})+A[i];
			dp[i][1]=max({dp[i-1][1], dp[i-1][2]})-A[i];
			dp[i][2]=dp[i-1][2]+A[i];
		}
		else{
			dp[i][0]=-INF;
			dp[i][1]=max({dp[i-1][0], dp[i-1][1], dp[i-1][2]})-A[i];
			dp[i][2]=max({dp[i-1][1], dp[i-1][2]})+A[i];
		}
	}
	cout<<max({dp[n][0], dp[n][1], dp[n][2]})<<'\n';
		
	return 0;
}
