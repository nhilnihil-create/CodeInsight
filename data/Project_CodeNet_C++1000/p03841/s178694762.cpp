#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int x[512];
int a[260000], m;
int cnt[512];
pair<int, pair<int, int>> dat[512];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		// position, remaining times, number
		dat[i] = make_pair(x[i], make_pair(i - 1, i));
	}
	sort(&dat[1], &dat[n + 1]);
	int q = 1; // slack
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n && m < dat[i].first - 1; j++)
		{
			while (m < dat[i].first - 1 && dat[j].second.first>0)
			{
				a[++m] = dat[j].second.second;
				dat[j].second.first--;
				cnt[dat[j].second.second]++;
			}
		}
		while (q < i && m < dat[i].first - 1)
		{
			if (cnt[dat[q].second.second] == n) {
				q++; continue;
			}
			a[++m] = dat[q].second.second;
			cnt[dat[q].second.second]++;
		}
		if (m != dat[i].first - 1 || dat[i].second.first != 0)
		{
			flag = true; break;
		}
		a[++m] = dat[i].second.second;
		dat[i].second.first--;
		cnt[dat[i].second.second]++;
	}
	if (flag) printf("No\n");
	else
	{
		while (q <= n)
		{
			if (cnt[dat[q].second.second] == n) {
				q++; continue;
			}
			a[++m] = dat[q].second.second;
			cnt[dat[q].second.second]++;
		}
		printf("Yes\n");
		for (int i = 1; i <= m; i++) printf("%d%c", a[i], i == m ? '\n' : ' ');
	}
	return 0;
}
