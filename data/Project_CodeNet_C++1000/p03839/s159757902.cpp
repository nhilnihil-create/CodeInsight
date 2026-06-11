#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#ifndef __MACRO_H__
#define __MACRO_H__

#define all(collection)  (collection).begin(), (collection).end()		// begin to end
#define rep(i, begin, end) for (ll i = begin; i < end; i++)				// repeat
#define repr(i, begin, end) for (ll i = begin; end < i; i--)			// repeat reverse

#endif

namespace AGC008B
{
	void Run(void)
	{
		ll n, k; cin >> n >> k;
		vector<ll> a(n);
		rep(i, 0, n)
			cin >> a[i];

		ll l = 0;
		ll r = k - 1;
		vector<ll> ans_w(1);
		rep(i, 0, n)
			ans_w[0] += (0 < a[i] && k <= i) ? a[i] : 0;
		while (1)
		{	// 白く塗ったKマスをスライドさせて累積
			l++; r++;
			if (r == n)
				break;

			ans_w.push_back(ans_w.back());
			ans_w.back() += (0 < a[l - 1]) ? a[l - 1] : 0;
			ans_w.back() += (0 < a[r]) ? -a[r] : 0;
		}

		l = 0;
		r = k - 1;
		vector<ll> ans_b(1);
		rep(i, 0, n)
			ans_b[0] += (i < k) ? a[i] : (k <= i && 0 < a[i]) ? a[i] : 0;
		while (1)
		{	// 黒く塗ったKマスをスライドさせて累積
			l++; r++;
			if (r == n)
				break;

			ans_b.push_back(ans_b.back());
			ans_b.back() += (0 < a[l - 1]) ? 0 : -a[l - 1];
			ans_b.back() += (0 < a[r]) ? 0 : a[r];
		}

		cout << max(*max_element(all(ans_w)), *max_element(all(ans_b)));
	}
};

int main(void)
{
	AGC008B::Run();
	return 0;
}
