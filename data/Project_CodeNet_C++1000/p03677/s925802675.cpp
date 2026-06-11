#include <stdio.h>
#pragma warning(disable:4996)
//FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
FILE *in = stdin, *out = stdout;
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 0x7fffffff
#define NM 100005
#define MOD 1000000007
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define sd(n) fscanf(in,"%lf",&n)
typedef long long int ll;
struct LIST {
	int x, y;
	LIST() {}
	LIST(int x, int y) :x(x), y(y) {}
	bool operator<(const LIST& rhs) {
		return x < rhs.x;
	}
}Q1[NM], Q2[NM];
int N1, N2;
vector<int> X1[NM], X2[NM], Y1[NM], Y2[NM];
int a[NM], n, m;
ll ans[NM];
void input() {
	si(n); si(m);
	FOR(i, 1, n) {
		si(a[i]);
		if (i == 1) continue;
		if (a[i] > a[i - 1]) {
			Q1[++N1] = LIST(a[i - 1], a[i]);
			X1[Q1[N1].x].push_back(N1);
			Y1[Q1[N1].y].push_back(N1);
		}
		else {
			Q2[++N2] = LIST(a[i], a[i - 1]);
			X2[Q2[N2].x].push_back(N2);
			Y2[Q2[N2].y].push_back(N2);
		}
	}
}
void solve_inc(LIST Q[], vector<int> X[], vector<int> Y[], int N) {
	int HN = 0;
	ll tot = 0;
	FOR(i, 1, N) tot += Q[i].y - Q[i].x;
	int cnt = 0;
	FOR(i, 1, m) {
		for (auto &idx: X[i - 1]){
			tot -= Q[idx].y - Q[idx].x;
			tot += Q[idx].y;
			cnt++;
		}
		ans[i] += tot - (ll)cnt * (i - 1);
		for (auto &idx:Y[i]){
			tot -= Q[idx].y;
			tot += Q[idx].y - Q[idx].x;
			cnt--;
		}
	}
}
void solve_dec(LIST Q[], vector<int> X[], vector<int> Y[], int N) {
	ll tot = 0, cnt = N;
	FOR(i, 1, N) tot += Q[i].x;
	ans[1] += tot;
	FOR(i, 2, m) {
		for (auto &idx : X[i - 1]) {
			tot -= Q[idx].x;
			tot += (m - Q[idx].y) + Q[idx].x;
			cnt--;
		}
		ans[i] += tot + cnt * (1 - i);
		for (auto &idx : Y[i]) {
			tot -= (m - Q[idx].y) + Q[idx].x;
			tot += m + Q[idx].x;
			cnt++;
		}
	}
}
int main() {
	input();
	solve_inc(Q1, X1, Y1, N1);
	solve_dec(Q2, X2, Y2, N2);
	ll res = 1e18;
	FOR(i, 1, m) res = min(res, ans[i]);
	fprintf(out, "%lld", res);
	return 0;
}