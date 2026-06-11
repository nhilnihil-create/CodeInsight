#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

const int maxn = 2e3+5;
const int intinf = 1<<29;
const ll inf = 1ll<<60;


void GG(){cout<<"No\n"; exit(0);}


vector<int> tree[maxn];
int nx = 0;
int k;
bool seen[maxn];

int dfs(int at, int left){
	if (left<0) return 0;
	seen[at]=1;
	int re = 1;
	for (int &v: tree[at]){
		if (!seen[v]) re+=dfs(v,left-1);
	}
	seen[at]=0;
	return re;
}

int solve(int x){
	int ex = 0, aa = 1;
	seen[x]=1;
	for (int &v: tree[x]){
		int a = dfs(v, k/2-1), b = dfs(v,k/2);
		aa += a; MXTO(ex, b-a);
		//debug(v); debug(a); debug(b);
	}
	seen[x]=0;
	return aa + ex;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   	int n; cin>>n>>k;
   	REP(i,n-1) {
   		int a, b; cin>>a>>b; tree[a-1].pb(b-1); tree[b-1].pb(a-1);
   	}
   	int re = intinf;
   	REP(i,n){
   		fill(seen, seen+n, 0); 
   		//dfs(i,0);
   		if (k&1) nx = solve(i);
   		else{
   			nx = dfs(i,k/2); 
   		}
   		MNTO(re, n-nx);
   	}
   	cout<<re<<endl;
}