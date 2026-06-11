#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 100100100;
const ll llINF = 1LL << 60;
string s = "";
int Size;
ll chmin(ll a, ll b)
{
	return a > b ? b : a;
}
int main()
{
	cin >> s;
	reverse(s.begin(), s.end());
	Size = s.size();
	int i = 0;
	while(i < Size) {
		auto dreamItr = s.find("maerd", i);
		auto dreamerItr = s.find("remaerd", i);
		auto eraseItr = s.find("esare", i);
		auto eraserItr = s.find("resare", i);
		if (i == dreamItr)	i += 5;
		else if (i == dreamerItr)	i += 7;
		else if (i == eraseItr)	i += 5;
		else if (i == eraserItr)	i += 6;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
