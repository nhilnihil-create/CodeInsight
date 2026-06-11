#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1 << 30;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100;

int main() {
	int a, b; cin >> a >> b;
	if (a%3==0 || b%3==0 || (a+b)%3==0) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}
