#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 200000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 1;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] += ren[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf1, uf2;
#include<map>
typedef pair<int, int>pii;
int main()
{
	int num, w1, w2;
	scanf("%d%d%d", &num, &w1, &w2);
	uf1.init(), uf2.init();
	for (int i = 0; i < w1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		uf1.unite(za, zb);
	}
	for (int i = 0; i < w2; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		uf2.unite(za, zb);
	}
	map<pii,int>ma;
	for (int i = 0; i < num; i++)ma[make_pair(uf1.find(i), uf2.find(i))]++;
	for (int i = 0; i < num; i++)printf("%d\n", ma[make_pair(uf1.find(i), uf2.find(i))]);
}