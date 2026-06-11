#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int maxn = 0;
int n , a[100009];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == i + 1)
		{
			swap(a[i] , a[(i + 1) % n]);
			ans++;
		}
	}
	cout << ans << endl;
}