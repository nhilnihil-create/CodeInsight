#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
using namespace std;
 
 
 
int n;
#define MAX 100002
 
vector<int> v[MAX];
int gr[MAX];
 
inline void dfs(int b,int pr=-1) {
	if (v[b].size() == 1 && pr != -1) {
		gr[b] = 0;
		return;
	}
	for (int i = 0; i < v[b].size(); i++) {
		int go = v[b][i];
		if (go != pr) {
			dfs(go,b);
			gr[b] ^= (gr[go] + 1);
		}
	}
}
 
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	if (gr[0]) {
		puts("Alice");
	}
	else {
		puts("Bob");
	}
	return 0;
}