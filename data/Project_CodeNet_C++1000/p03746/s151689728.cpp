#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1000000007;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}

int n, m;
vector<int> es[100010];
bool use[100010];
int r1[100010];
void rec(int s,int &i) {

	use[s] = true;
	r1[i] = s;
	i++;
	for(auto nex : es[s])
	{
		if (use[nex]) continue;
		use[nex] = true;
		return rec(nex, i);
	}
}
void solv() {

	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		es[a].push_back(b);
		es[b].push_back(a);
	}
	use[1] = true;
	int ind = 0;
	rec(1,ind);
	vector<int> ar;
	for (size_t i = 0; i < ind; i++)
	{
		ar.push_back(r1[i]);
	}

	for (size_t i = 1; i <= n; i++)
	{
		use[i] = false;
	}
	for (auto val : ar)
	{
		use[val] = true;

	}
	if (es[1].size() > 0) {
		int ind2 = 0;
		for (size_t i = 1; i < es[1].size(); i++)
		{
			if (use[es[1][i]]) continue;
			rec(es[1][i], ind2);
			break;
		}

		if (ind2 > 0) {
			for (size_t i = 0; i < ind2; i++)
			{
				ar.insert(ar.begin(),r1[i]);
			}
		}
	}
	cout << ar.size() << endl;
	for (size_t i = 0; i < ar.size() ; i++)
	{
		if (i > 0) cout << " ";
		cout << ar[i];
	}
	cout << endl;
}




int main() {
	solv();

	return 0;
}
