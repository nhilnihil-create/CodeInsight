#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
#define INF int(1e9)
#define N 200000
#define MP make_pair
typedef pair<int, int> P;
typedef pair<pair<P, P>, P>PP;
long long int k;
long long int ans[50];
int main()
{
	cin >> k;
	for (int i = 0; i < 50; i++)
	{
		ans[i] -= k / 50;
	}
	for (int i = 0; i < k % 50; i++)
	{
		ans[i] -= 50 - k % 50 + 1;
	}
	for (int i = k%50; i < 50; i++)
	{
		ans[i] += k % 50;
	}
	for (int i = 0; i < 50; i++)
	{
		ans[i] = 49 - ans[i];
	}
	cout << 50 << endl;
	for (int i = 0; i < 50; i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}