#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int N, M;
int ret;
int a[1000010];
int num[100010];
vi vec[100010];

int solve(int p, int q) //p<q
{
	priority_queue<pii> q1, q2;

	map<int,int> m1, m2;
	for (int x:vec[p]) {
		++m1[x];
	}
	for (int x:vec[q]) {
		++m2[x];
	}

	for (const pii pr:m1) {
		q1.push(mp(pr.se & 1, pr.se));
	}

	for (const pii pr:m2) {
		q2.push(mp(pr.se & 1, pr.se));
	}

	int res = 0;

	while (q1.size()>0&&q2.size()>0) {
		pii p1 = q1.top(); q1.pop();
		pii p2 = q2.top(); q2.pop();
		++res;
		p1.fi ^= 1;
		p2.fi ^= 1;
		p1.se--;
		p2.se--;
		if (p1.se) {
			q1.push(p1);
		}
		if (p2.se) {
			q2.push(p2);
		}		
	}

	while (!q1.empty()) {
		pii p1 = q1.top(); q1.pop();
		res += p1.se / 2;
	}

	while (!q2.empty()) {
		pii p2 = q2.top(); q2.pop();
		res += p2.se / 2;
	}

	return res;
}

int main() {
	cin >> N >> M;

	rep(i, N) {
		int X;
		cin >> X;
		a[i] = X;
		++num[X%M];
		vec[X%M].pb(X);
	}

	ret = num[0]/2;
	if (M%2==0) {
		ret += num[M/2]/2;
	}

	for (int i = 1; i < M; ++i) {
		if (i >= M - i) break;
		ret += solve(i, M-i);
	}

	cout << ret << endl;

	return 0;
}