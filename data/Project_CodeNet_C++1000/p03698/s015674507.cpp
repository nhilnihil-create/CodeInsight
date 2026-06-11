#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s; cin >> s;
	string t = s;
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	if (t.size() == s.size()) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
