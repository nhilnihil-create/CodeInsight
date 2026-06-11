#include <bits/stdc++.h>

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <map>
// #include <vector>
// #include <algorithm>
// #include <regex>
// #include <chrono>
// #include <sstream>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <set>
// #include <unordered_map>
// #include <unordered_set>


using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
#define int long long
struct IoSetup {
    IoSetup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
}IoSetup;

typedef long long ll;
typedef pair < int , int >  pii;
typedef vector<int> vec;
typedef vector< vec > Mat;
static const signed int INF = 0x3f3f3f3f;
static const signed long long LINF = 0x3f3f3f3f3f3f3f3fLL;
static const signed int SMOD = 1000000007;
static const signed int NMOD = 998244353;
static const signed int dx[]={1,0,-1,0,1,1,-1,-1};
static const signed int dy[]={0,-1,0,1,-1,1,-1,1};

bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T&b){if(a<b)return(a=b,1);return 0;}
template<class T>bool chmin(T &a, const T&b){if(b<a)return(a=b,1);return 0;}

int n, m;
vector<pii> edge[1010];
Mat tour, retour;
vector<bool> node, renode;
int a[3010], b[3010], c[3010];

void dfs(int p, Mat& mat, vector<bool>& lis) {
	for(int i = 0; i < mat[p].size(); i++) {
		int v = mat[p][i];
		if(lis[v]) continue;

		lis[v] = true;
		dfs(v, mat, lis);
	}
}


signed main() {

	cin >> n >> m;

	for(int i = 0; i < m; i++) {

		cin >> a[i] >> b[i] >> c[i];
		c[i] = -c[i];
	}

	vec dist(n+1,LINF);	
	dist[1] = 0;
	for(int j = 0; j < n-1; j++) {
		for(int i = 0; i < m; i++) {

			if(dist[a[i]] == LINF) continue;
			chmin(dist[b[i]], dist[a[i]] + c[i]);
		}
	}

	ll ans = dist[n];

	vector<bool> neg(n+1, false);

	for(int j = 0; j < n; j++) {
		for(int i = 0; i < m; i++) {

			if(dist[a[i]] == LINF) continue;
			if(chmin(dist[b[i]], dist[a[i]] + c[i]))
				neg[b[i]] = true;
			
			if(neg[a[i]])
				neg[b[i]] = true;
		}
	}

	if(neg[n]) cout << "inf\n";
	else cout << -ans << endl;
			   

    return 0;
}

