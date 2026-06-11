#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fst first
#define snd second
const ll mod = 1000000007;
const ll INF = mod * mod;

int p[2][200010];
int prank[2][200010];
int card[200010];

int findp(int v, int kind) {
	if (v != p[kind][v])return (p[kind][v]=findp(p[kind][v], kind));
	else return v;
}

bool isUnion(int v1, int v2, int kind) {
	return (findp(v1,kind) == findp(v2,kind));
}

void link(int x, int y, int kind) {
	if (isUnion(x, y, kind))return;
	int px, py;
	px = findp(x, kind);
	py = findp(y, kind);
	if (prank[py] < prank[px]) {
		p[kind][py] = px;
	}
	else {
		if (prank[kind][px] == prank[kind][py])prank[kind][py]++;
		p[kind][px] = py;
	}
	return;
}

int main(){
	int n,k,l;
	cin >> n>>k>>l;
	for (int i = 0; i < n; i++) {
		p[0][i] = p[1][i] = i;
		prank[0][i] = prank[1][i] = 0;
		card[i] = 1;
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		link(--x, --y, 0);
	}
	for (int i = 0; i < l; i++) {
		int x, y;
		cin >> x >> y;
		link(--x, --y, 1);
	}
	pii lis[200010],lis_s[200010];
	for (int i = 0; i < n; i++) {
		lis[i] = lis_s[i] = make_pair(findp(i, 0), findp(i, 1));
	}
	sort(lis_s, lis_s + n);
	for (int i = 0; i < n; i++) {
		cout << upper_bound(lis_s, lis_s + n, lis[i]) - lower_bound(lis_s, lis_s + n, lis[i]) << endl;
	}

	return 0;
}
