/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/29 14:07:27 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

/* #include <boost/multi_array.hpp> */
/* #include <boost/optional.hpp> */
/* #include <boost/range/irange.hpp> */
/* #include <boost/range/algorithm.hpp> */
/* #include <boost/range/adaptors.hpp> */
/* #include <boost/multiprecision/cpp_int.hpp> */
/* #include <boost/algorithm/string/classification.hpp> // is_any_of */
/* #include <boost/algorithm/string/split.hpp> */
/* #include <boost/algorithm/string/join.hpp> */
/* #include <boost/algorithm/string/replace.hpp> */
/* #include <boost/math/tools/minima.hpp> */
/* namespace adaptor = boost::adaptors; */
/* using boost::math::tools::brent_find_minima; */
/* using boost::irange; */
/* using boost::algorithm::join; */
/* using boost::algorithm::split; */
/* using boost::algorithm::replace_all; */
/* using boost::multiprecision::cpp_int; */

#define MOD 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	bitset<1000001>	bs;
	ll	n, m, k;
	cin >> n >> m >> k;
	if (n == 1 || m == 1)
	{
		cout << "Yes" << endl;
		return ;
	}
	ll	a;
	a = n * m;
	rep(i, m + 1)
		bs.set(i * n);
	rep (i, n + 1)
		bs.set(i * m);
	for (int y = 1; y < n; y++)
	{
		for (int x = 1; x < m; x++)
			bs.set(x * y + (m - x) * (n - y));
	}
	// if (min(n, m) > 2)
	// {
		// ll	l, r;
		// l = max(n, m);
		// r = a - l;
		// ll	x;
		// x = min(n, m) - 2;
		// for (ll i = 0; l + x * i <= r; i++)
		// 	bs.set(l + x * i);
	// }
	if (bs.test(k))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
