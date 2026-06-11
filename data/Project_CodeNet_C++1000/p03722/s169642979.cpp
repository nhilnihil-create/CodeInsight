#include <bits/stdc++.h>
using namespace std;

int	main()
{
	const static int64_t	inf = static_cast<int64_t>(1e+9 * 2000) + 1;
	int	N, M;
	cin >> N >> M;
	vector<int64_t>				v_score(N, -inf);
	map<int, map<int, int64_t>>	e_score;
	map<int, int>	prev_map;
	int	a, b;
	int64_t	c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		--a; --b;
		if (!e_score.count(a))
			e_score[a] = map<int, int64_t>(); 
		e_score.at(a)[b] = c;
	}
	bool	updated = false;
	v_score.at(0) = 0;
	int64_t	tmp_score;
	set<int>	updated_set;
	for (int i = 0; i < N; ++i) {
		updated = false;
		updated_set.erase(updated_set.begin(), updated_set.end());
		for (a = 0; a < N; ++a) {
			if (v_score.at(a) == -inf)
				continue;
			if (!e_score.count(a))
				continue;
			for (auto pr : e_score.at(a)) {
				b = pr.first;
				tmp_score = v_score.at(a) + pr.second;
				if (tmp_score > v_score.at(b)) {
					v_score.at(b) = tmp_score;
					updated = true;
					prev_map[b] = a;
					updated_set.insert(b);
				}
			}
		}
		if (!updated)
			break;
	}
	bool	has_posi_cycle = false;
	for (b = N - 1; b != 0; b = prev_map.at(b)) {
		if (updated_set.count(b)) {
			has_posi_cycle = true;
			break;
		}
	}
	if (v_score.at(0) > 0)
		has_posi_cycle = true;
	if (has_posi_cycle)
		cout << "inf" << endl;
	else
		cout << v_score.at(N - 1) << endl;
}
