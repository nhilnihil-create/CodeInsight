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
const ll INF = 1LL << 60;
const int inf = 1 << 25;
ll n, m, k, y,a, q, d, w = 0, sum = 0, ans = INF; string s;
const int MOD = 1000000007;
int main(void) {
	cin >> n; vector<ll> v(n + 1, 0);
	req(i, n) {
		cin >> v[i];v[i] += v[i - 1];
	}
	req(i, n-1) {
		ans = min(ans, (ll)abs(v[n] -v[i] - v[i]));
	}cout << ans << endl;
}