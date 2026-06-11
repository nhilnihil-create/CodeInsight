#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

const int bound = 100010;
vector<int> graph[bound];

string mode = "right";

int sz = 0;
vector<int> l;
vector<int> r;
bool bscht[100010];

void dfs( int node ){
	bscht[node] = true;
	++sz;
	if( mode == "right" ) r.push_back(node);
	else if ( mode == "left" ) l.push_back(node);
	for( auto &next : graph[node] ){
		if( bscht[next] ) continue;
		dfs(next);
		break;
	}
}

int main(){
	int n, m; cin >> n >> m;
	for( int i = 0; i < m; ++i ){
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(0);
	bscht[0] = false;
	mode = "left";
	dfs(0);
	reverse( l.begin(), l.end() );
	cout << sz-1 << endl;
	for( int i = 0; i < l.size()-1; ++i ) cout << l[i]+1 << ' ';
	for( int i = 0; i < r.size(); ++i  ) cout << r[i]+1 << ' ';
	cout << endl;
}