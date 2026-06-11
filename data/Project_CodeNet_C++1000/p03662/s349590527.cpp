#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005
using namespace std;

int n, cnt, a[2][N];
vector<int> v[N];

void f(int p, int q, int c) {
	int i;
	if (a[p][q]) return;
	a[p][q] = c;
	for (i = 0; i < v[q].size(); i++) f(p, v[q][i], c + 1);
}

int main()
{
	int i, t1, t2;
	cin >> n;
	for (i = 1; i < n; i++) {
		scanf("%d %d", &t1, &t2);
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	f(0, 1, 1);
	f(1, n, 1);
	for (i = 1; i <= n; i++) cnt += a[0][i] <= a[1][i];
    cout << (cnt > n - cnt ? "Fennec" : "Snuke") << endl;
    return 0;
}