#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bitset>
#include <ctime>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int a[maxN], b[maxN];

int main(){
	time_t START = clock();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, cnt = 0; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++){
		a[i] = lower_bound(b, b + n, a[i]) - b;
		cnt += (i % 2 ^ a[i] % 2);
	}
	printf("%d\n", cnt / 2);
	time_t FINISH = clock();
	cerr << "Execution time: " << (ld)(FINISH - START) / CLOCKS_PER_SEC * 1000.0 << " milliseconds.\n";
	return 0;
}
 

