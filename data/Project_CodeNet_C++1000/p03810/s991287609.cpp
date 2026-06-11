//Sasayego! Sasayego! Shinzou wo Sasageyo!

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
#define lid (id << 1)
#define rid (lid ^ 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int a[maxN], cnt[2];

int gcd(int a, int b){
	return (!b ? a : gcd(b, a % b));
}

int main(){
	time_t START = clock();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		if (a[i] != 1)
			cnt[a[i] & 1]++;
	}
	for (int x = 0; ; x++){
		if ((cnt[0] & 1) == 1)
			return printf(x & 1 ? "Second\n" : "First\n"), 0;
		if (cnt[1] != 1)
			return printf(x & 1 ? "First\n" : "Second\n"), 0;
		int g = 0;
		for (int i = 0; i < n; i++){
			if (a[i] != 1 && (a[i] & 1))
				a[i]--;
			g = gcd(g, a[i]);
		}
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i < n; i++){
			a[i] /= g;
			if (a[i] != 1)
				cnt[a[i] & 1]++;
		}
	}
	time_t FINISH = clock();
	cerr << "Execution time: " << (ld)(FINISH - START) / CLOCKS_PER_SEC * 1000.0 << " milliseconds.\n";
	return 0;
}
 
