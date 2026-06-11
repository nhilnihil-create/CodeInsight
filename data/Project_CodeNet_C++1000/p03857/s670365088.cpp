#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int par1[213456], par2[213456];//親
int depth1[213456], depth2[213456];//木の深さ
//n要素で初期化
void init1(int n) {
	for (int i = 0; i <= n; i++) { par1[i] = i; depth1[i] = 0; }
}
void init2(int n) {
	for (int i = 0; i <= n; i++) { par2[i] = i; depth2[i] = 0; }
}
//木の根を求める
int find1(int x) {
	if (par1[x] == x) { return x; }
	else { return par1[x] = find1(par1[x]); }
}
int find2(int x) {
	if (par2[x] == x) { return x; }
	else { return par2[x] = find2(par2[x]); }
}
//xとyの属する集合を併合
void unite1(int x, int y) {
	x = find1(x); y = find1(y);
	if (x == y) { return; }
	if (depth1[x] < depth1[y]) { par1[x] = y; }
	else { par1[y] = x; if (depth1[x] == depth1[y])depth1[x]++; }
}
void unite2(int x, int y) {
	x = find2(x); y = find2(y);
	if (x == y) { return; }
	if (depth2[x] < depth2[y]) { par2[x] = y; }
	else { par2[y] = x; if (depth2[x] == depth2[y])depth2[x]++; }
}
//xとyが同じ集合に属するか否か
bool same1(int x, int y) {
	return find1(x) == find1(y);
}
bool same2(int x, int y) {
	return find2(x) == find2(y);
}
signed main() {
	int n, k, l, a, b, c, d; cin >> n >> k >> l;
	vector<vector<int>>test(n + 1, vector<int>(2));
	map<int, map<int, int> > ok;
	init1(n + 1); init2(n + 1);
	for (int h = 0; h < k; h++) {
		cin >> a >> b; unite1(a, b);
	}
	for (int h = 1; h <= n; h++) {
		test[h][0] = find1(h);
	}
	for (int h = 0; h < l; h++) {
		cin >> c >> d; unite2(c, d);
	}
	for (int h = 1; h <= n; h++) {
		test[h][1] = find2(h);
	}
	for (int h = 1; h <= n; h++) {
		ok[test[h][0]][test[h][1]]++;
	}
	for (int h = 1; h <= n; h++) {
		if (h == 1) { cout << ok[test[h][0]][test[h][1]]; }
		else { cout << ' ' << ok[test[h][0]][test[h][1]]; }
	}
	cout << endl;
	return 0;
}