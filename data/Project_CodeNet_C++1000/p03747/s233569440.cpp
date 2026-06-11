#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>  
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int ans[200000] = {};
int main() {
#define int long long
	int n, l, t;
	cin >> n >> l >> t;
	vector<pair<int, int>> input;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		if (b == 1) {
			input.push_back(make_pair(a, 1));
		}
		else {
			input.push_back(make_pair(a, -1));
		}
	}
	vector<int> positions;
	for (int i = 0; i < n; ++i) {
		int now_position = input[i].first;
		now_position += input[i].second * (t % l);
		now_position %= l;
		now_position += l;
		now_position %= l;
		positions.push_back(now_position);
	}
	int starter = positions[0];
	sort(positions.begin(), positions.end());
	int now_cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (input[i].second != input[0].second) {
			if (input[0].second == 1) {
				int first_step = input[i].first - input[0].first;
				int now_ans = 2*t;
				if (first_step < now_ans) {
					now_ans -= first_step;
					now_cnt += 1LL + (now_ans - 1) / l;
					now_cnt %= n;
				}
			}
			else {
				int first_step = (l - input[i].first) + input[0].first;
				int now_ans = 2LL * t;
				if (first_step < now_ans) {
					now_ans -= first_step;
					now_cnt -= 1LL + (now_ans - 1) / l;
					now_cnt += n * (abs(now_cnt) / n + 1);
					now_cnt %= n;
				}
			}
		}
	}
	int now_itr = 0;
	if (input[0].second == 1) {
		for (int i = 0; i < positions.size(); ++i) {
			if (positions[i] == starter) {
				now_itr = i;
				break;
			}
		}
	}
	else {
		for (int i = positions.size() - 1; i >= 0; --i) {
			if (positions[i] == starter) {
				now_itr = i;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		ans[now_cnt] = positions[(now_itr+i)%n];
		now_cnt++;
		now_cnt %= n;
	}
	REP(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}
