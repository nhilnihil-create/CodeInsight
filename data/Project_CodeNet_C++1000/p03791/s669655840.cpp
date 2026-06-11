#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

#define MOD 1000000007

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i)
		cin >> a[i];

	ll ans = 1;
	int l=0;
	for(int i=0; i<n; ++i)
	{
		int maxk = (a[i])/2;
		int need_remove = l + max(0,i-maxk-l);
		need_remove = max(need_remove, l);
		l = need_remove;
		int k = (i+1-l);
		if(a[i]%2==0 && i-maxk-l == 0)
			++l;
		//print3(k, l, i-maxk)
		ans = (ans * k) % MOD;
	}
	
	cout << ans << "\n";

	return 0;
}
