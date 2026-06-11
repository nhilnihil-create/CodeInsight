/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/25 07:27:05 by monoue           ###   ########.fr       */
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

#define MOD 1e9+7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	ll	n;
	cin >> n;
	vector<ll>	VA(n);
	vector<ll>	VB(n);
	rep(i, n)
	{
		ll	x, y;
		cin >> x >> y;
		// VA.at(i) = x % y;
		VA.at(i) = x;
		VB.at(i) = y;
	}
	ll	cnt;
	cnt = 0;
	ll	adder;
	adder = 0;
	rrep(i, n - 1)
	{
		if ((VA.at(i) + adder) % VB.at(i) == 0)
			continue;
		adder += VB.at(i) * ((VA.at(i) + adder) / VB.at(i) + 1) - (VA.at(i) + adder);
	}
	cout << adder << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}

	// ll	v;
	// v = VB.at(0);
	// if (VA.at(0) % v != 0)
	// {
	// 	rep(i, n)
	// 		VA.at(i) += v - (VA.at(0) % v);
	// 	cnt += v - (VA.at(0) % v);
	// }
	// ll	maxdif;
	// maxdif = 0;
	// for (int i = 1; i < n; i++)
	// {
	// 	if (VA.at(i) != 0)
	// 		maxdif = max(maxdif, VB.at(i) - VA.at(i));
	// }
	// if (maxdif > 0)
	// 	cnt += v * ((maxdif + (v - 1)) / v);