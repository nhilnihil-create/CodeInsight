#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;
typedef long long LL;
int a[105];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if(m == 1)
	{
		printf("%d\n", n);
		if(n == 1)
		{
			printf("1\n1");
			return 0;
		}
		printf("2\n");
		printf("%d %d\n", 1, n-1);
		return 0;
	}
	int cnt = 0;
	for(int i = 0; i< m; i++)
	{
		scanf("%d", a+i);
		if(a[i]%2) cnt++;
	}
	if(cnt>2)
	{
		printf("Impossible\n");
		return 0;
	}
	for(int i = 1; i< m-1; i++)
	{
		if(a[i]%2)
		{
			if(a[0]%2) swap(a[i], a[m-1]);
			else swap(a[i], a[0]);
		}
	}
	for(int i = 0; i< m; i++) printf("%d ", a[i]);
	printf("\n");
	vector<int> ans;
	if(a[0]> 1) ans.pb(a[0]-1);
	for(int i = 1; i< m-1; i++) ans.pb(a[i]);
	ans.pb(a[m-1]+1);
	printf("%d\n", ans.size());
	for(int i = 0; i< (int) ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}