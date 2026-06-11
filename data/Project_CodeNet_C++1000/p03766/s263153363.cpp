#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

const nagai mod = 1000000007;

void md(nagai& x)
{
	if (x >= mod)
		x -= mod;
}

int main()
{
	int n; 
	cin >> n;
	vector<nagai> cnt(n + 1);
	cnt[0] = 1;
	cnt[1] = n;
	nagai cursum = 0;
	for (int i = 2; i <= n; ++i)
	{
		md(cnt[i] += cnt[i - 1]);
		(cnt[i] += 1LL * (n - 2 + 1) * (n - 1)) %= mod;
		int cnt0 = (n - 2 + 1) - (i - 3 - 0 + 1);
		md(cnt[i] += cnt0);
		md(cnt[i] += cursum);
		md(cursum += cnt[i - 2]);
		//for (int k = 2; k <= n; ++k)
			//md(cnt[i] += cnt[max(0, i - k - 1)]);
		//cerr << cnt[i] << ' ';
	}
	//cerr << endl;
	cout << cnt.back() << endl;

}
