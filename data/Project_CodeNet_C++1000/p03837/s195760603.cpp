#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;

int main(){
	int n,m;
	cin >> n >> m;
	//接続する2頂点の辺をみて,その辺の長さよりそれらの最短経路が真に小さいならそれは使わない.
	int d[100][100];
	for(int i = 0;i < 100;i++){
		for(int j = 0;j < 100;j++){
			d[i][j] = INF;
		}
	}
	vector<T> edges;
	for(int i = 0;i < m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--,b--;
		d[a][b] = c;
		d[b][a] = c;
		edges.push_back(T(a,b,c));
	}

	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++)d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
		}
	}

	int ans = 0;
	for(int i = 0;i < m;i++){
		int a,b,c;
		tie(a,b,c) = edges[i];
		if(d[a][b] != c)ans++;
	}

	cout << ans << endl;
}
