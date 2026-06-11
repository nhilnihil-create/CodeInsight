#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// CODE FESTIVAL 2016 qual A-C, 1048, 
	string s; int k; cin >> s >> k;
	int len = s.size();
	rep(i, len) {
		if (s[i] == 'a') continue;
		if ('z' - s[i] + 1 <= k) {
			k -= 'z' - s[i] + 1;
			s[i] = 'a';
		}
	}
	k %= 26;
	s.back() += k;
	if ('z' < s.back()) s.back() -= 26;
	cout << s << endl;
	return 0;
}