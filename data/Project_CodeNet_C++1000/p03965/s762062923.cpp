#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <limits>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()

int main()
{
	string s;
	cin >> s;
	int N = s.size();
	int p = 0;
	rep(i, N) {
		if (s[i] == 'p')
			p++;
	}
	auto ans = N/2 - p;
	cout << ans << endl;
	return 0;
}
