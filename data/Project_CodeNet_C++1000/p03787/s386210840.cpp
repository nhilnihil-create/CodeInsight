#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 100005;

long long n, m, cnt, a, b, e;
int bio[MAXN], c[MAXN], moze[MAXN], siz[MAXN];
vector <int> v[MAXN];

void dfs (int x, int boja) {
	if (bio[x]) return;
	bio[x] = cnt;
	siz[cnt]++;
	c[x] = boja;
	for (int i=0; i<v[x].size(); i++) {
		int sus = v[x] [i];
		if (c[sus] == c[x]) moze[cnt] = 1;
		dfs(sus, -boja);
	}
}

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1; i<=n; i++) {
		if (!bio[i]) {
			cnt++;
			dfs(i, 1);
		}
	}
	for (int i=1; i<=cnt; i++) {
		if (siz[i] == 1) {
			e++;
		} else {
			if (moze[i]) a++; else b++;
		}
	}
	cout << a*a + 2*a*b + 2*b*b + 2*n*e - e*e;
	return 0;
}
