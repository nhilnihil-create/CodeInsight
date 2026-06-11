# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <numeric>
# include <tuple>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
#define ALL(x)    (x).begin(),(x).end()
#define UNIQ(c)   (c).erase(unique(ALL((c))), end((c)))
#define mp        make_pair
#define eb        emplace_back
typedef pair<LL, LL> P;
typedef pair<P, P> PP;
template<typename A, typename B>inline void chmin(A &a, B b) { if (a > b)a = b; }
template<typename A, typename B>inline void chmax(A &a, B b) { if (a < b)a = b; }

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if (H%h == 0 && W%w == 0 ) {
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	int num = 999;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (i%h == 0 && j%w == 0) {
				cout <<-num* (h*w-1)-1;
			}
			else {
				cout << num;
			}
			if (j != W)cout << " ";
			else cout << endl;
		}
	}
	//system("pause");
}