#include<cstdio>
#include<map>
using namespace std;
int n, K, L;
int p1[200200], p2[200200];
map<pair<int, int>, int> sz;
int root(int* p, int x)
{
	return p[x] == x ? x : p[x] = root(p, p[x]);
}
int main()
{
	scanf("%d%d%d", &n, &K, &L);
	for (int i = 1; i <= n; i++) {
		p1[i] = p2[i] = i;
	}
	for (int i = 1; i <= K; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		p1[root(p1, p)] = root(p1, q);
	}
	for (int i = 1; i <= L; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		p2[root(p2, p)] = root(p2, q);
	}
	for (int i = 1; i <= n; i++)
	{
		auto key = make_pair(root(p1, i), root(p2, i));
		auto it = sz.find(key);
		if (it == sz.end()) sz[key] = 1;
		else it->second++;
	}
	for (int i = 1; i <= n; i++)
	{
		auto key = make_pair(root(p1, i), root(p2, i));
		printf("%d%c", sz[key], i == n ? '\n' : ' ');
	}
	return 0;
}
