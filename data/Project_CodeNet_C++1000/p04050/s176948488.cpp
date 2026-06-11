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
	vector<int>A(M);
	rep(i, M)cin >> A[i];

	if (N <= 2) {
		rep(i, M) {
			if (i)cout << " ";
			cout << A[i];
		}
		cout << endl;
		cout << 1 << endl << N << endl;
		return 0;
	}
	if (M == 1) {
		cout << A[0] << endl << 2 << endl << A[0] - 1 << " " << 1 << endl;
		return 0;
	}
	if (M == 2) {
		sort(ALL(A));
		rep(i, M) {
			if (i)cout << " ";
			cout << A[i];
		}
		cout << endl;
		cout << 2 << endl << A[0] + 1 << " " << A[1] - 1 << endl;
		return 0;
	}

	vector<int>odd;
	rep(i, M)if (A[i] % 2 == 1)odd.push_back(A[i]);
	if (3 <= odd.size()) {
		cout << "Impossible" << endl;
		return 0;
	}
	sort(ALL(odd));
	vector<int>ansa;
	if (odd.size())ansa.push_back(odd[0]);
	rep(i, M)if (A[i] % 2 == 0)ansa.push_back(A[i]);
	if (odd.size() == 2)ansa.push_back(odd[1]);
	rep(i, M) {
		if (i)cout << " ";
		cout << ansa[i];
	}
	cout << endl;
	cout << (ansa[0] == 1 ? M - 1 : M) << endl;
	if (ansa[0] != 1)cout << ansa[0] - 1;
	REP(i, 1, M - 1)cout << " " << ansa[i];
	cout << " " << ansa[M - 1] + 1 << endl;


	return 0;
}