#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int N=510;

int n, m, k, u, v, x, y, t, a, b;
int A[N], ans[N*N];
int R[N*N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> vec[N*N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(R, 31, sizeof(R));
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		R[i*n+i]=--A[i];
		for (int j=i; j; j--) R[i*n+j-1]=R[i*n+j]-1;
	}
	vec[A[0]].pb(0);
	for (int i=1; i<n; i++) pq.push({R[i*n], i*n});
	
	for (int i=0; i<n*n; i++){
		for (int v:vec[i]) pq.push({R[v], v});
		if (pq.empty()) kill("No")
		int v=pq.top().second;
		pq.pop();
		if (R[v]<i) kill("No")
		int num=v/n, t=v%n;
		ans[i]=num;
		if (t!=n-1){
			t++;
			if (t==num) vec[A[num]].pb(v+1);
			else pq.push({R[v+1], v+1});
		}
	}
	cout<<"Yes\n";
	for (int i=0; i<n*n; i++) cout<<ans[i]+1<<" ";cout<<"\n";
	
	return 0;
}
