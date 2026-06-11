#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;
 
int H, W, N;
set<pair<int, int> > F;
set<pair<int, int> > cand;
 
i64 ans[10];
 
void add_cand(int y, int x)
{
	if (y >= 0 && y < H - 2 && x >= 0 && x < W - 2) cand.insert({ y, x });
}
 
int main()
{
	scanf("%d%d%d", &H, &W, &N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		F.insert({ a, b });
 
		for (int dy = 0; dy <= 2; ++dy) for (int dx = 0; dx <= 2; ++dx) add_cand(a - dy, b - dx);
	}
 
	for (int i = 0; i <= 9; ++i) ans[i] = 0;
	ans[0] = (i64)(H - 2) * (W - 2);
	for (auto aa : cand) {
		int y = aa.first, x = aa.second;
		int num = 0;
		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
			if (F.count({ y + i, x + j })) ++num;
		}
		--ans[0];
		++ans[num];
	}
	for (int i = 0; i <= 9; ++i) printf("%lld\n", ans[i]);
 
	return 0;
}