#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

//ワーシャルフロイト法のテンプレ.graphに最短経路が格納される.
//負の重みがある場合inf + const = inf に気を付けること.
//graphは隣接行列.
void WF(vector<vector<int>> &graph){
	int n = graph.size();
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(n, inf));
	vector<pair<int, int>> edges;
	vector<int> dist(m);
	rep(i, n)
	{
		graph[i][i] = 0;
	}
	rep(i,m){
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		graph[a][b] = c;
		graph[b][a] = c;
		dist[i] = c;
		edges.push_back(pair<int, int>(a, b));
	}

	WF(graph);
	int ans = 0;
	rep(i, m)
	{
		pair<int, int> ab = edges[i];
		int a = ab.first, b = ab.second;
		int unused = 1;
		rep(j, n)
		{
			if (graph[j][a] + dist[i] == graph[j][b]) {
				unused = 0;
				break;
			}
		}
		ans += unused;
	}
	cout << ans << endl;

	return 0;
}