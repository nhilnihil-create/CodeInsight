#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int a[100010];
vector<int> vt;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int q;
		scanf("%d", &q);
		vt.push_back(q);
		a[q]++;
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());
	if (vt.size() == 1) {
		if (vt[0] == n - 1||n/2>=vt[0])puts("Yes");
		else puts("No");
		return 0;
	}
	int t = vt.size();
	if (vt[t - 1] - vt[0] > 1) {
		puts("No");
		return 0;
	}
	if (a[vt[0]] + 1 <= vt[1] && vt[1] <= a[vt[0]] + a[vt[1]] / 2)
		puts("Yes");
	else
		puts("No");
}