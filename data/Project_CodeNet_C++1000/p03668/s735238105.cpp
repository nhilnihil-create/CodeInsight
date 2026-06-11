#include<map>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;

ll const MAX = 100005;
ll gr[MAX];
vector<ll> children[MAX];
vector<ll> G[MAX];
ll parent[MAX];

void grundy(ll x) {
	ll ans = 0;
	for (ll i = 0; i < children[x].size(); i++) {
		ll c = children[x][i];
		ll cnt = 1 + gr[c];
		ans ^= cnt;
	}
	gr[x] = ans;
}

int main() {
	ll n;
	cin >> n;
	REP(i, 1, n - 1) {
		ll x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	stack<ll> st1,st2;
	st1.push(1); st2.push(1);
	parent[1] = 1;
	while (!st1.empty()) {
		ll cur = st1.top();
		st1.pop();
		for (ll i = 0; i < G[cur].size(); i++) {
			ll next = G[cur][i];
			if (next != parent[cur]) {
				children[cur].push_back(next);
				parent[next] = cur;
				st1.push(next);
				st2.push(next);
			}
		}
	}
	while (!st2.empty()) {
		ll cur = st2.top();
		st2.pop();
		grundy(cur);
	}
	if (gr[1] == 0) {
		cout << "Bob" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
}