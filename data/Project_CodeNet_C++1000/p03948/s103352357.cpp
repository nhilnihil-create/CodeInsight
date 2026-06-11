#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define Mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f 
#define MEM(x,y) memset(x,y,sizeof(x))
#define Maxn 100005
#define P pair<int,int>
using namespace std;
int main()
{
	int n, q;
	cin >> n >> q;
	int a[100005];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int max1 = 0;
	int temp = INF;
	for (int i = 0; i <n; i++)
	{
		temp = min(temp, a[i]);
		max1 = max(a[i]-temp, max1);
	}
	temp = INF;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		temp = min(temp, a[i]);
		if (max1 == a[i] - temp)
			ans++;
	}
	cout << ans;
}