#include <bits/stdc++.h>
#define pb push_back
#define sz(V) ((int)(V).size())
using namespace std;
typedef long long ll;
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }

const int MAXN = 100005;

vector<int> G[MAXN];

int dep[MAXN], cnt[MAXN];

int N;

void f(int i, int d) {
	dep[i] = d;
	int c = 0, x = 0;
	for(int v : G[i]) {
		if(dep[v]) continue;
		f(v, d+1);
		c++;
		x ^= cnt[v];
	}
	cnt[i] = x + 1;
}

int main() {
	cin >> N;
	for(int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		fg(G, a, b);
	}
	f(1, 1);
	puts(1 == cnt[1] ? "Bob" : "Alice");
	return 0;
}