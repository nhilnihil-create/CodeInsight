#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

vector <int> v[100005];
int p[100005];

vector <int> a;
int sol[100005];

void dfs(int node, int par) {
	p[node] = par;
	for (int i=0 ; i<v[node].size() ; i++) {
		if (v[node][i] != par) dfs(v[node][i], node);
	}
	a.pb(node);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=2 ; i<=n ; i++) {
		int x;
		scanf("%d", &x);
		v[i].pb(x);
		v[x].pb(i);
	}
	dfs(1, 0);
	for (int i=0 ; i<n ; i++) {
		int x = a[i];
		vector <int> deca;
		for (int j=0 ; j<v[x].size() ; j++) {
			if (v[x][j] == p[x]) continue;
			deca.pb(sol[v[x][j]]);
		}
		sort(deca.begin(), deca.end());
//		reverse(deca.begin(), deca.end());
		int ut = 0;
		for (int j=0 ; j<deca.size() ; j++) {
			ut = max(ut+1, deca[j]+1);
			/*if (x == 1) {
				cout <<"deca["<<j<<"] = "<<deca[j]<<endl;
				cout <<"ut = "<<ut<<endl;
			}*/
			sol[x] = max(sol[x], ut);
		}
	}
	//for (int i=1 ; i<=n ; i++) printf("%d ", sol[i]);
	printf("%d\n", sol[1]);
	return 0;
}