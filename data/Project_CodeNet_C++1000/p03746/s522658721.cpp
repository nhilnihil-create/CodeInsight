#if 1
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <set>
#include <map>
#include <numeric>
#include <cassert>

using namespace std;
#define int long long
#define uint unsigned long long
constexpr int MOD = 1000000007;
constexpr int INF = 1145141919810;

#define LOADVEC(type,name,N) std::vector<type>name(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name[nnn]; \
}

#define LOADVEC2(type,name0,name1,N) std::vector<type>name0(N),name1(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn]; \
}

#define LOADVEC3(type,name0,name1,name2,N) std::vector<type>name0(N),name1(N),name2(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn];cin >> name2[nnn]; \
}

#define LOAD(type,name) type name; \
cin >> name;


void proc();

signed main() {
	ios::sync_with_stdio(false);
	proc();
	return 0;
}

/*
--------------------------------------------------------
--------------------------------------------------------
---------------    template      ----------------------
--------------------------------------------------------
--------------------------------------------------------
*/

void proc() {
	LOAD(int, N);
	LOAD(int, M);
	std::vector<int>A(M), B(M);
	std::unordered_map<int, std::set<int>> link;
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
		cin >> B[i];
		link[A[i]].insert(B[i]);
		link[B[i]].insert(A[i]);
	}
	//
	std::vector<int> path0, path1;
	unordered_set<int> vertexes = { A[0] ,B[0] };
	path0.push_back(A[0]);
	path1.push_back(B[0]);
	//
	while (true) {
	a:
		for (auto next : link[path0.back()]) {
			auto itr = vertexes.find(next);
			if (itr == vertexes.end()) {
				path0.push_back(next);
				vertexes.insert(next);
				goto a;
			}
		}
		break;
	}


	while (true) {
	b:
		for (auto next : link[path1.back()]) {
			auto itr = vertexes.find(next);
			if (itr == vertexes.end()) {
				path1.push_back(next);
				vertexes.insert(next);
				goto b;
			}
		}
		break;
	}
	//
	cout << path0.size() + path1.size() << endl;
	std::vector<int> path2(path0.size());
	for (int i = 0; i < path0.size(); ++i) {
		path2[path0.size() - 1 - i] = path0[i];
	}
	//
	for (int i = 0; i < path2.size(); ++i) {
		cout << path2[i] << " ";
	}
	for (int i = 0; i < path1.size(); ++i) {
		cout << path1[i];
		if (i != path1.size() - 1) {
			cout << " ";
		}
	}
}


#endif
