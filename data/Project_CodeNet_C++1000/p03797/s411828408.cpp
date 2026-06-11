#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>
#include <map>
#include <vector>
#include <queue>
#include <list>
#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void){
	ll a, b;
	cin >> a >> b;
	if (a > 0 && b > 1) {
		ll ans = 0;
		ans = min(a, b / 2);
		b -= 2 * ans;
		ans += b / 4;
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}