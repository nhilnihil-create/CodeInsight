#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>graph(n+1, vector<int>(0));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph.at(x).push_back(y);
		graph.at(y).push_back(x);
	}
	queue<int>s;
	s.push(1);
	vector<int>ed(n+1,-1);
	ed.at(1) = 1;
	int x = s.front();
	for (int i = 0; i < graph.at(x).size(); i++) {
		if (ed.at(graph.at(x).at(i)) == -1) {
			s.push(graph.at(x).at(i));
			ed.at(graph.at(x).at(i)) = 1;
		}
	}
	s.pop();
	while (s.size() >= 1) {
		int y = s.front();
		for (int i = 0; i < graph.at(y).size(); i++) {
			if (ed.at(graph.at(y).at(i)) == -1) ed.at(graph.at(y).at(i)) = 1;
		}
		s.pop();
	}
	if (ed.at(n) != -1)cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
}