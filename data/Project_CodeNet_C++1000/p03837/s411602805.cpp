#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const ll INF=1<<30;

vector<vector<ll>> next_path(201,vector<ll>(201,0));
ll d[201][201];// d[u][v]は辺e=(u,v)のコスト(存在しない場合はINF、ただしd[i][i]=0とする) 
ll V;// 頂点数
void warshall_floyd() {
	for (ll k = 1; k <=V; k++){
		for (ll i = 1; i <= V; i++){
			for (ll j = 1;j <= V; j++){ 
			if (d[i][j] > d[i][k] + d[k][j]){
				d[i][j] = d[i][k] + d[k][j];
			}
			}
		}
	}
}

void printPath3(ll start, ll goal) {
	cout << start << " " << goal << endl;
    for (ll cur = start; cur != goal; cur = next_path[cur][goal]){
       d[cur][next_path[cur][goal]] = LINF;
	   cout << cur << " " << next_path[cur][goal] << endl;
	}
	cout << goal << endl;
	cout << endl;
}

int main(){
	ll m;cin>>V>>m;
	for(int i = 0; i <= 200; i++) {
		for(int j = 0; j <= 200; j++) {
			if(i != j){
				d[i][j] = INF;
			}
		}
	}
	vector<int> a(m);
	vector<int> b(m);
	vector<int> c(m);
	for(ll i = 0; i < m; i++) {
		ll x,y,z;cin>>x>>y>>z;
		a[i] = x;
		b[i] = y;
		c[i] = z;
		d[x][y] = z;
		d[y][x] = z;
	}
	for(ll i = 1; i <= V; i++) {
		for(ll j = 1; j <= V; j++) {
			next_path[i][j] = j;
		}
	}
	warshall_floyd();
	int ans = 0;
	for(int i = 0; i < m; i++) {
		bool flag = false;
		for(int j = 1; j <= V; j++) {
			for(int k = 1; k <= V; k++) {
				if(j != k){
					if (d[j][a[i]] + c[i] + d[b[i]][k] == d[j][k]){
						flag = true;
					}
				}
			}
		}
		if(!flag)ans++;
	}
	cout << ans << endl;

	return 0;
}