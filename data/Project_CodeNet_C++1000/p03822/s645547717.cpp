#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int N, a[100000], g[100000],c[100000],cnt[100000];
vector<int>V[100000];
queue<int>q;
int main() {
	cin >> N;
	for (int i = 1; i != N; ++i) {
		cin >> a[i];
		--a[i];
		V[a[i]].push_back(i);
		++c[a[i]];
	}
	for (int i = 0; i != N; ++i) {
		if (!c[i])
			q.push(i);
	}
	while (true) {
		vector<int>v;
		for (int j = 0; j != V[q.front()].size(); ++j) {
			v.push_back(g[V[q.front()][j]]);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i != v.size(); ++i) {
			g[q.front()] = max(g[q.front()] + 1, v[i] + 1);
		}
		if (!q.front())break;
		++cnt[a[q.front()]];
		if (cnt[a[q.front()]] == c[a[q.front()]])
			q.push(a[q.front()]);
		q.pop();
	}
	cout << g[0] << endl;
	return 0;
}