#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 100004

vector<int> v[MAX];
int dist[MAX];
bool color[MAX];
int parent[MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i < n+1; i++) {
		dist[i] = -1;
	}
	dist[1] = 0;
	parent[1] = -1;
	queue<int> p,q,r;
	q.push(1);
	int now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (dist[next] == -1) { 
			dist[next] = dist[now] + 1; 
			parent[next] = now;
			q.push(next);
			}
		}
		if (dist[n] != -1) { break; }
	}
	int d = dist[n];
	d = (d - 1) / 2;
	int bound = n;
	for (int i = 0; i < d; i++) {
		bound = parent[bound];
	}
	int fineck = 1; int sunuke = 1;
	p.push(1); r.push(n);
	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
	}
	dist[1] = 0;
	while (!p.empty()) {
		now = p.front();
		p.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (dist[next] == -1 && next != bound) {
				dist[next] = dist[now] + 1;
				fineck++;
				p.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
	}
	dist[n] = 0;
	bound = parent[bound];
	while (!r.empty()) {
		now = r.front();
		r.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (dist[next] == -1 && next != bound) {
				dist[next] = dist[now] + 1;
				sunuke++;
				r.push(next);
			}
		}
	}
	if (fineck > sunuke) { cout << "Fennec" << endl; }
	else { cout << "Snuke" << endl; }
}