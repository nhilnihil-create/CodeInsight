#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 7;
int lst[Max];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)scanf("%d", &lst[i]);
	sort(lst + 1, lst + n + 1, greater<int>());
	ll res = 0;
	for (int i = 1; i <= k; i++)res += lst[i];
	cout << res;
}