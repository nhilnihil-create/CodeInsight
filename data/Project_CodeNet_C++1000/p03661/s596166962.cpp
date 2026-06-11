#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl

ll N, a[100000 * 2 + 10], sum[100000 * 2 + 10], ans = 1000000000000000000;

int main() {
	rd(N);
	repi(i, 0, N) {
		rd(a[i]);
		if (i == 0) sum[i] = a[i];
		else sum[i] = sum[i - 1] + a[i];
	}
	repi(i, 0, N - 1) {
		ans = min(ans, abs(sum[i] - (sum[N - 1] - sum[i])));
	}
	wrln(ans);
	return 0;
}