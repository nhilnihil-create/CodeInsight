#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N;
long A[size];
vector<int> g[size];
bool dfs(int p, int v){
	long sum = 0; long grt = 0;
	for(int u:g[v]){
		if(u == p) continue;
		if(!dfs(v, u)) return false;
        grt = max(grt, A[u]);
		sum += A[u];
	}
    if(g[v].size() == 1) return true;
    long t = 2 * A[v] - sum;
    if(0 <= t && max(t, grt) <= A[v]){ A[v] = t; return true; }
    else return false;
}
int main(){
	cin>>N;
	rep(i,0,N) cin>>A[i];
    if(N == 2){ cout<<(A[0] == A[1] ? "YES" : "NO")<<endl; return 0; }
	int a,b;
	rep(i,0,N-1){
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
    rep(i,0,N)if(g[i].size() > 1){
        if(dfs(-1, i) && A[i] == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
}