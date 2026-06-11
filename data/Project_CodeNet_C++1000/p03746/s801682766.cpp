#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005 ///////////////////////////////////////////
using namespace std;

int n, m;
bool v[N];
vector<int> a[N], b, ans;
void f(int p) {
	int i;
	if (v[p]) return;
	v[p] = 1;
	b.push_back(p);
	for (i = 0; i < a[p].size(); i++) {
		if (!v[a[p][i]]) {f(a[p][i]); break;}
	}
}
int main()
{
	int i, t1, t2;
	cin >> n >> m;
	while (m--) {
		scanf ("%d %d", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	f(1);
	for (i = 0; i < b.size(); i++) ans.push_back(b[i]);
	b.clear();
	v[1] = 0;
	f(1);
	cout << ans.size() + b.size() - 1 << endl;
	for (i = b.size() - 1; i >= 0; i--) printf("%d ", b[i]);
	for (i = 1; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
    return 0;
}
