/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 12:30:15 by monoue            #+#    #+#             */
/*   Updated: 2020/04/24 11:18:40 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
// #include <boost/multi_array.hpp>
// #include <boost/optional.hpp>
// #include <boost/range/irange.hpp>
// #include <boost/range/algorithm.hpp>
// #include <boost/range/adaptors.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/algorithm/string/classification.hpp> // is_any_of
// #include <boost/algorithm/string/split.hpp>
// #include <boost/algorithm/string/join.hpp>
// #include <boost/algorithm/string/replace.hpp>
// #include <boost/math/tools/minima.hpp>

#define MOD 1e9+7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

// namespace adaptor = boost::adaptors;
using namespace std;
// using boost::math::tools::brent_find_minima;
// using boost::irange;
// using boost::algorithm::join;
// using boost::algorithm::split;
// using boost::algorithm::replace_all;
// using boost::multiprecision::cpp_int;
using ll = long long;
using P = pair<int, int>;

// TOP
void	Main()
{
	ll	n, c, k;
	cin >> n >> c >> k;

	vector<ll>	V(n);
	rep(i, n)
		cin >> V.at(i);
	sort(V.begin(), V.end());
	ll	bus;
	bus = 0;
	int i = 0;
	while (i < n)
	{
		bus++;
		int	cnt;
		cnt = 0;
		ll limit;
		limit = V.at(i) + k;
		while (i < n - 1 && cnt < c - 1 && V.at(i + 1) <= limit )
		{
			cnt++;
			i++;
		}
		i++;
	}
	cout << bus << endl;
}
// END

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	Main();
}
