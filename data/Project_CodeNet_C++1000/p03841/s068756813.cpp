#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;


int N, x, c[500];
pair<int, int>p[500];
vector<int>v;

int main() {
	cin >> N;
	for (int i = 0; i != N; ++i) {
		cin >> x;
		c[i] = 0;
		p[i] = mkp(x - 1, i);
	}
	sort(p, p + N);
	for (int i = 0; i != N*N; ++i) {
		bool b = true;
		for (int j = 0; j != N; ++j) {
			if (c[p[j].second] == p[j].second&&i == p[j].first) {
				++c[p[j].second];
				v.push_back(p[j].second);
				b = false;
				break;
			}
		}
		if (b) {
			for (int j = 0; j != N; ++j) {
				if (c[p[j].second] < p[j].second&&i < p[j].first) {
					++c[p[j].second];
					v.push_back(p[j].second);
					b = false;
					break;
				}
			}
			if (b) {
				for (int j = 0; j != N; ++j) {
					if (c[p[j].second] < N&&c[p[j].second] > p[j].second&&i > p[j].first) {
						++c[p[j].second];
						v.push_back(p[j].second);
						break;
					}
				}
			}
		}
	}
	if (v.size() != N*N) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		for (int i = 0; i != N*N; ++i) {
			cout << v[i]+1 << sp;
		}
		cout << endl;
	}
	return 0;
}