#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vt;
int a[250002];
int cnt[501];
int visited[250001];
pair<int, int> b[501];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	for (int i = 1; i <= n; i++)
		cnt[i] = n;
	sort(b+1, b + n+1);
	int left = 1;
	for (int i = 1; i <= n; i++)
	{
		visited[b[i].first] = 1;
		cnt[b[i].second]--;
		a[b[i].first] = b[i].second;
		for (int y = 0; y < b[i].second - 1; y++)
		{
			while (a[left])
				left++;
			a[left] = b[i].second;
			cnt[b[i].second]--;
		}
		if (left > b[i].first)
		{
			puts("No");
			return 0;
		}
	}
	int update = 0;
	for (int i = 1; i <= n*n; i++)
	{
		if (!a[i]) {
			if (vt.size() == update)
			{
				puts("No");
				return 0;
			}
			a[i] = vt[update];
			cnt[a[i]]--;
			if (!cnt[a[i]])
				update++;
			
		}
		if (visited[i]) {
			if(cnt[a[i]])
				vt.push_back(a[i]);
		}
	}
	puts("Yes");
	for (int i = 1; i <= n*n; i++)
		printf("%d ", a[i]);
}