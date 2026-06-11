#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll INF =  1LL << 60;
const int inf = 1 << 20;
int n, m, x, y, q, d,z, w = 0, sum, ans = 0;
vector<int>a;
const int MAX = 510000;
const int MOD = 1000000007;
int main(void) {
	string s; cin >> s;
	reverse(ALL(s));
	string t[4] = { "resare","esare","remaerd","maerd" };
	rep(i, s.size()) {
		if (s.substr(i, 5) == t[1] || s.substr(i, 5) == t[3]) {
			i += 4; continue;
		}if (s.substr(i, 6) == t[0]) {
			i += 5; continue;
		}if (s.substr(i, 7) == t[2]) {
			i += 6; continue;
		}
		cout << "NO" << endl;
		return 0;
	}cout << "YES" << endl;
}