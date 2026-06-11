#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long lint;

int N;
const int MAX_N = 100005;
lint a[MAX_N],out[MAX_N];
int deg[MAX_N];
bool chk[MAX_N];

mat path,ind;

bool f(int v){
	lint sum = 0;
	for(int u:ind[v]){
		sum += out[u];
	}
	if(a[v] > sum || 2*a[v] < sum)return false;
	out[v] = 2*a[v] - sum;

	for(int u:ind[v]){
		if(out[u]>sum/2){
			if(out[v] < 2*out[u]-sum)return false;
		}
	}
	return true;
}

bool solve(){
	queue<int> Q;
	for(int i=1;i<=N;i++){
		if(deg[i]==1){
			chk[i] = 1;
			out[i] = a[i];
			Q.push(i);
		}
	}

	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		sort(ind[v].begin(),ind[v].end());

		for(int u:path[v]){
			if(chk[u]){
				auto it = lower_bound(ind[v].begin(),ind[v].end(),u);
				if(it==ind[v].end() || *it!=u)return out[v]==out[u];
				continue;
			}
			ind[u].push_back(v);
			deg[u]--;

			if(deg[u]==1){
				chk[u] = 1;
				if(!f(u))return false;
				Q.push(u);
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> a[i];
	}

	path.assign(N+1,vec());
	ind.assign(N+1,vec());
	for(int i=0,x,y;i<N-1;i++){
		cin >> x >> y;
		path[x].push_back(y);
		path[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}

	if(solve()){
		puts("YES");
	}else{
		puts("NO");
	}

	return 0;
}