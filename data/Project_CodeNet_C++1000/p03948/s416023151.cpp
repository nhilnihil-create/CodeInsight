#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define x first
#define y second
#define sz(a) ((int)(a.size()))

const int MAX = 500005;
const int mod = 998244353;
int a[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	int n , t;
	cin >> n >> t;
	map<int, int> res;
	for(int i = 0; i < n; i++)	
		cin >> a[i];
	int ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		ans = max(ans , a[i]);
		res[ans - a[i]]++;
	}
	cout << (--res.end())->y;
			
}
