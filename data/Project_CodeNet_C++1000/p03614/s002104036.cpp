#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

int vec[100001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &vec[i]);

	// 우선순위는 둘다 같을 경우.
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i != n && vec[i] == i && vec[i + 1] == i + 1) {
			swap(vec[i], vec[i + 1]);
			cnt++;
		}
		else if (vec[i] == i) {
			if (i == 1) {
				swap(vec[i], vec[i + 1]);
				cnt++;
			}
			else {
				swap(vec[i], vec[i - 1]);
				cnt++;
			}
		}
	}

	printf("%d", cnt);
}