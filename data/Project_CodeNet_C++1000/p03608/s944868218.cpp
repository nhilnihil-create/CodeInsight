#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <lli>>;
const int mod = 1e9 + 7;
const lli inf = 1e18;

const int N = 2e5 + 1;
int n,m,R;
vector <int> r;
vvint adj;

void floyd(){
	for(int k = 0;k < n;++k){
		for(int i = 0;i < n;++i){
			for(int j = 0;j < n;++j){
				if(adj[i][k] + adj[k][j] < adj[i][j]){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
	return;
}

void solve(){
	cin >> n >> m >> R;
	r = vector <int> (R);
	for(int i = 0;i < R;++i){
		int num;
		cin >> num;
		--num;
		r[i] = num;
	}
	sort(r.begin(),r.end());
	adj = vvint(n,vector <lli>(n,inf));
	for(int i = 0;i < m;++i){
		int a,b,c;
		cin >> a >> b >> c;
		--a;--b;
		adj[a][b] = c;
		adj[b][a] = c;
	}
	floyd();
	lli minn = 2e18;
	do{
		lli summ = 0;
		for(int i = 1;i < R;++i){
			summ = summ + adj[r[i]][r[i - 1]];
		}
		minn = min(minn,summ);
	}while(next_permutation(r.begin(),r.end()));
	cout << minn << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
