#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
namespace fio {
	streambuf* in = cin.rdbuf();
	char bb[1000000], * s = bb, * t = bb;
#define gc() (s==t&&(t=(s=bb)+in->sgetn(bb,1000000), s==t)?EOF: *s++)
	inline int read() {
		int x = 0;
		char ch = gc();
		while (ch < 48)ch = gc();
		while (ch >= 48)x = x * 10 + ch - 48, ch = gc();
		return x;
	}
}using fio::read;
int n, k;
vector<int>road[100005];
int arr[100005], ans;
int dfs(int x, int dep) {
	int maxn = dep; for (int it : road[x])maxn = max(maxn, dfs(it, dep + 1));
	if (arr[x] - 1 && maxn - dep == k - 1)return ans++, 0; return maxn;
}
int main() {
	n = read(), k = read();
	arr[1] = 1, ans = read() != 1;
	for (int i = 2; i <= n; i++)road[arr[i] = read()].push_back(i);
	dfs(1, 0), cout << ans;
}
