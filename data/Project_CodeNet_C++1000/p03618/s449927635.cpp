#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	string s;
	cin >> s;
	vi alph(26);
	rep(i, s.size())alph[s[i] - 'a']++;
	ll same = 0;
	for (int x : alph)same += (ll)x * (x - 1) / 2;
	cout << (ll)s.size() * (s.size() - 1) / 2 - same + 1 << endl;

}