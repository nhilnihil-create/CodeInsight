#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n;
int* a = new int[100005];
int* a_copy = new int[100005];
map<int, int> mp;
int cnt;
int ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a_copy[i] = a[i];
	}
	sort(a_copy + 1, a_copy + n + 1);
	for (int i = 1; i <= n; i++)mp[a_copy[i]] = i;
	for (int i = 1; i <= n; i++)
	{
		if (mp[a[i]] % 2 != i % 2)
		{
			cnt++;
		}
	}
	ans = cnt / 2;
	cout << ans << endl;
	return 0;
}