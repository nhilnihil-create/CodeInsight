#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int h, w;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> h >> w;
	FOR(i, h) FOR(j, w) {
		string s;
		cin >> s;
		if (s == "snuke") {
			cout << (char)('A'+j) << i+1 << endl;
		}
	}
	return 0;
}