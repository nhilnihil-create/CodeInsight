#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	string s; cin >> s;
	int g = 0, p = 0;
	for (char x : s)
	{
		if (x == 'g')++g;
		else ++p;
	}
	cout << (g - p) / 2 << endl;
}
