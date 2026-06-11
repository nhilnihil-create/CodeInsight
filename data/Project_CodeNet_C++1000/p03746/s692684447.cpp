#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int maxn = 1e5 + 10;

vector<int> g[maxn];
bool visited[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int fi, se;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		fi = v, se = u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	visited[fi] = visited[se] = 1;
	deque<int> deq;
	deq.push_front(fi);
	deq.push_back(se);
	while (true){
		bool flag = 0;
		for (auto v : g[fi]){
			if (!visited[v]){
				visited[v] = 1;
				deq.push_front(v);
				flag = 1;
				fi = v;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	while (true){
		bool flag = 0;
		for (auto v : g[se]){
			if (!visited[v]){
				visited[v] = 1;
				deq.push_back(v);
				flag = 1;
				se = v;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	cout << deq.size() << endl;
	for (int i = 0; i < deq.size(); i++)
		cout << deq[i] << " ";
	cout << endl;
}
