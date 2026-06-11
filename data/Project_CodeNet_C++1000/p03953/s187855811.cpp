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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=61;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], B[MAXN], C[MAXN];
int P[MAXN], sp[MAXN][LOG];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++) B[i]=A[i]-A[i+1], P[i]=i;
	cin>>m>>k;
	while (m--){
		cin>>x;
		swap(P[x-1], P[x]);
	}
	for (int i=1; i<n; i++) sp[i][0]=P[i];
	for (int j=1; j<LOG; j++) for (int i=1; i<n; i++) sp[i][j]=sp[sp[i][j-1]][j-1];
	
	for (int i=1; i<n; i++){
		C[i]=i;
		for (int j=0; j<LOG; j++) if ((k>>j)&1) C[i]=sp[C[i]][j];
	}
	for (int i=n-1; i; i--) A[i]=B[C[i]]+A[i+1];
	
	for (int i=1; i<=n; i++) cout<<A[i]<<'\n';
	
	return 0;
}
