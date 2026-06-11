#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>> edge(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	deque<int> deq;
	deq.push_front(1), deq.push_back(edge[1][0]);
	vector<bool> vi(N + 1);
	vi[1] = true, vi[edge[1][0]] = true;

	bool flag = true;
	while (flag) {
		flag = false;
		int left = deq.front();
		for (auto to:edge[left]) {
			if (vi[to])continue;
			vi[to] = true;
			deq.push_front(to);
			flag = true;
			break;
		}

		int right = deq.back();
		for (auto to : edge[right]) {
			if (vi[to])continue;
			vi[to] = true;
			deq.push_back(to);
			flag = true;
			break;
		}
	}

	cout << deq.size() << endl;
	for (int i = 0; i < deq.size(); i++) {
		cout << deq[i] << " ";
	}
}
