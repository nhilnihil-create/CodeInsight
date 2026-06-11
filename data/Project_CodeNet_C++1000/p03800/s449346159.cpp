#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

bool claim[100001]; // true : 両隣同じ

bool kind[100001]; // true : 羊
				   // false : 狼

bool next_animal(bool before, bool animal, bool say) {
	if (animal) {
		if (say) return before;
		else return !before;
	}
	else {
		if (say) return !before;
		else return before;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		if (c == 'o') claim[i] = true;
	}

	for (int i = 1; i >=0; i--) {
		for (int j = 1; j >=0; j--) {
			bool flag = true;
			
			kind[0] = i;
			kind[1] = j;
			for (int k = 1; k <= N - 1; k++) kind[k + 1] = next_animal(kind[k - 1], kind[k], claim[k]);

			// チェック
			if (kind[0] != kind[N]) flag = false;
			if (kind[1] != next_animal(kind[N - 1], kind[0], claim[0])) flag = false;

			if (flag) {
				string S;
				for (int i = 0; i < N; i++) {
					if (kind[i]) S.push_back('S');
					else S.push_back('W');
				}
				cout << S << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

	return 0;
}