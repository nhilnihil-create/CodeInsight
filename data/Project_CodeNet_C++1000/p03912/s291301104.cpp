#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
//#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define EACH(i, a) for (auto i: a)
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define veccat(v1, v2) std::copy((v2).begin(),(v2).end(),std::back_inserter(v1)/*v1の後ろにv2を入れる*/)
#define intmax (std::numeric_limits<int64_t>::max() / 4)
using namespace std;
//typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int>card(100001);
	rep(i, N) {
		int X;
		cin >> X;
		card[X]++;
	}
	int ans = 0;

	vector<int>pair_modM(M);
	rep(i, 100001) {
		pair_modM[i%M] += card[i] / 2;
		ans += card[i] / 2;
		card[i] %= 2;
	}

	vector<int>card_modM(M);
	rep(i, 100001)if (card[i]) {
		card_modM[i%M]++;
	}
	
	ans += card_modM[0] / 2;
	card_modM[0] %= 2;
	if (M % 2 == 0) {
		ans += card_modM[M / 2] / 2;
		card_modM[M / 2] %= 2;
	}
	REP(i, 1, M) {
		if (M <= i * 2)break;
		const int mmm = min(card_modM[i], card_modM[M - i]);
		ans += mmm;
		card_modM[i] -= mmm;
		card_modM[M - i] -= mmm;
	}

	rep(i, M) {
		if (2 <= card_modM[i]) {
			if (pair_modM[M - i]) {
				const int mmm = min(pair_modM[M - i], card_modM[i] / 2);
				ans += mmm;
				pair_modM[M - i] -= mmm;
				card_modM[i] -= mmm * 2;

			}
		}
	}


	cout << ans << endl;
}