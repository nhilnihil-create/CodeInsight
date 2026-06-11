#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}
int main(void) {
	int n, m,p,q; cin >> n >> m;
	vector<ll> a(n+1, 0),b(n+1,0);
	rep(i, m) {
		cin >> p >> q; p--; q--;
		a[p]++; a[q]++;
	}
	rep(i, n) {
		if (a[i] % 2 == 1) {
			cout << "NO" << endl;
			return 0;
		}
	}cout << "YES" << endl;
}