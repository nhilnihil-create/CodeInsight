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

int N, p[100000 + 10], index, ans;

int main() {
	rd(N);
	repi(i, 0, N) rd(p[i]);

	while (1) {
		if (index == N - 2) {
			if (p[N - 2] == N - 1 || p[N - 1] == N) ans++;
			break;
		}
		else if (index == N - 1) {
			if (p[N - 1] == N) ans++;
			break;
		}
		else if (p[index] == index + 1) {
			ans++;
			index += 2;
		}
		else {
			index += 1;
		}
	}

	wrln(ans);

	return 0;
}