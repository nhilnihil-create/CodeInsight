#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	map<long long int, int> cnt;
	for (int i = 0; i < n; i++) {
		long long int v;
		cin >> v;
		if (cnt.find(v) == cnt.end())
			cnt[v] = 1;
		else
			cnt[v]++;
	}
	long long int comb[51][51] = {};
	for (int i = 0; i <= n; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
	auto itr = cnt.end();
	itr--;
	double ans_av;
	long long int ans_comb = 0;
	if ((*itr).second < a) {
		double sum = (*itr).first * (*itr).second;
		int cnt = (*itr).second;
		ans_comb = 1;
		itr--;
		while (cnt < a) {
			if ((*itr).second + cnt < a) {
				sum += (*itr).first * (*itr).second;
				cnt += (*itr).second;
			} else {
				sum += (*itr).first * (a - cnt);
				ans_comb = comb[(*itr).second][a - cnt];
				break;
			}
			itr--;
		}
		ans_av = (double)sum / (a + 0.0);
	} else {
		ans_av = (*itr).first;
		for (int i = a; i <= min(b, (*itr).second); i++) {
			ans_comb += comb[(*itr).second][i];
		}
	}
	printf("%.10f\n", ans_av);
	cout << ans_comb << endl;
}