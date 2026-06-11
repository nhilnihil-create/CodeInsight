#include <bits/stdc++.h>

int n, L, Q, lg;
std::vector <int> a;
std::vector <std::pair<int,int>> query;
std::vector <std::vector<int>> reach;

int main () {
	std::cin >> n;
	a.resize (n+1);
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	std::cin >> L >> Q;
	query.resize (Q);
	for (int i = 0; i < Q; ++i)
		std::cin >> query[i].first >> query[i].second;
	lg = std::__lg (n) + 2;
	std::cerr << "lg = " << lg << "\n";
	reach.assign (n+1, std::vector<int> (lg+1, 0));

	for (int i = 1; i <= n; ++i) {
		if (a[i] + L >= a[n])
			reach[i][0] = n;
		else
			reach[i][0] = std::upper_bound (a.begin()+1, a.end(), a[i]+L)-a.begin()-1;
	}
	for (int j = 1; j <= lg; ++j)
		for (int i = 1; i <= n; ++i)
			reach[i][j] = reach[reach[i][j-1]][j-1];
	for (int i = 0; i < Q; ++i) {
		int st = query[i].first, ed = query[i].second;
		if (st > ed) std::swap (st, ed);
		int ans = 0;
		for (int j = lg; j >= 0; --j)
			if (reach[st][j] < ed)
				st = reach[st][j], ans += (1<<j);
		std::cout << ans+1 << "\n";
	}
	return 0;
}