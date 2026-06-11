#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 100000

int N, M, a[maxN], orig[maxN], v[maxN], finals[maxN];
ll  K;

int main() {
	while (scanf("%d", &N) != EOF) {
		FOR(i, 0, N) scanf("%d", a + i);
		for (int i = N - 1; i; i--) a[i] = a[i] - a[i - 1];
		scanf("%d %lld", &M, &K);
		FOR(i, 0, N) orig[i] = i;
		FOR(i, 0, M) {
			int t;
			scanf("%d", &t);
			swap(orig[t], orig[t - 1]);
		}
		FOR(i, 0, N) {
			if (!v[i]) {
				int cc = 0;
				int next = i;
				while (next != i || !cc) {
					v[next] = true;
					next = orig[next];
					cc++;
				}
				int nv = (-K % cc + cc) % cc;
				FOR(j, 0, nv) next = orig[next];
				int st = i;
				FOR(j, 0, cc) {
					finals[st] = next;
					st = orig[st];
					next = orig[next];
				}
			}
		}
		FOR(i, 0, N) {
			orig[finals[i]] = a[i];
		}
		ll acum = 0;
		FOR(i, 0, N) {
			acum += orig[i];
			printf("%lld\n", acum);
		}
	}
	return 0;
}
