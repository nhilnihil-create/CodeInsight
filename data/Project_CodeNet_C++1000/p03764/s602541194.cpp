#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int n;
int m;

ll x[100010],y[100010];

vector<ll> h,w;

int main()
{
	cin >> n >> m;

	for(int i = 0;i < n;i++)
	{
		cin >> x[i];
	}
	for(int i = 0;i < m;i++)
	{
		cin >> y[i];
	}

	w.push_back(0);
	h.push_back(0);

	for(int i = 1;i < n;i++)
	{
		w.push_back(x[i] - x[i - 1]);
	}
	for(int i = 1;i < m;i++)
	{
		h.push_back(y[i] - y[i - 1]);
	}

	vector<ll> wdp(n + 2,0);
	vector<ll> use(n + 2,0);

	for(int i = 1;i < w.size();i++)
	{
		use[i] = (use[i - 1] + i * w[i]) % MOD;
		wdp[i] = (wdp[i - 1] + use[i]) % MOD;
	}

	vector<ll> hdp(m + 2,0);
	use.resize(m + 2,0);

	for(int i = 1;i < h.size();i++)
	{
		use[i] = (use[i - 1] + i * h[i]) % MOD;
		hdp[i] = (hdp[i - 1] + use[i]) % MOD;
	}

	cout << (wdp[w.size() - 1] * hdp[h.size() - 1]) % MOD << endl;
	return 0;
}
