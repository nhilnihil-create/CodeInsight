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
#define sd(n) fscanf(in,"%lld",&n)
typedef long long int ll;

int n, a[NM * 2];
ll sum = 0;
void input() {
	si(n);
	FOR(i, 1, n) si(a[i]), sum += a[i];
}
void pro() {
	ll res = 1e18, t = 0;
	FOR(i, 1, n - 1) {
		t += a[i]; sum -= a[i];
		res = min(res, abs(t - sum));
	}
	fprintf(out, "%lld", res);
}
int main() {
	input();
	pro();
	return 0;
}