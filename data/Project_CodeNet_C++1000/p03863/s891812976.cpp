#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const int MAX = 4;

static const ll MAX_N = 100001;
static const ll MAX_M = 100001;

int main() {
	string s; cin >> s;

	bool a = s[0] == s[s.size() - 1];
	bool b = s.size() % 2;
	cout << ((a ^ b) ? "First" : "Second") << endl;

	return 0;
}