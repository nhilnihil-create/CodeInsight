#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	string s;
	int K;
	cin >> s >> K;

	for (auto i = 0; i < (int)s.length(); ++i)
	{
		if (s[i] == 'a')
		{
			continue;
		}
		auto temp = (int)('z' - s[i]) + 1;
		if (temp <= K)
		{
			K -= temp;
			s[i] = 'a';
		}
	}

	if (K > 0)
	{
		auto num = K % ((int)('z' - 'a') + 1);
		s[(int)s.length() - 1] += num;
	}
	cout << s << endl;

	return 0;
}