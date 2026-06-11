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
const int MAXN=510, BIG=1000000;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>x>>y;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) A[i][j]=+BIG;
	if (m%y){
		for (int i=1; i<=n; i++) for (int j=y; j<=m; j+=y) A[i][j]=-((y-1)*BIG+1);
		cout<<"Yes\n";
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cout<<A[i][j]<<" \n"[j==m];
		return 0;
	}
	if (n%x){
		for (int i=x; i<=n; i+=x) for (int j=1; j<=m; j++) A[i][j]=-((x-1)*BIG+1);
		cout<<"Yes\n";
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cout<<A[i][j]<<" \n"[j==m];
		return 0;
	}
	kill("No")
	
	return 0;
}
