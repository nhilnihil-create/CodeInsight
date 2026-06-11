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

ll K;
ll N = 50, a[55];

int main() {
	rd(K);
	wrln(N);
	repi(i, 0, N) {
		if (i < (K%N)) wr((N - 1) + (K / N) + (N - (K%N) + 1));
		else wr((N - 1) + (K / N) - (K%N));
		if (i != N - 1) wr(" ");
		else cout << endl;
	}
	return 0;
}