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
bool getPos(int pos)
{
	//cout << "pos : " << pos << endl;
	if (pos == Size)	return true;
	if (pos > Size)	return false;
	int tmpPos;
	auto dreamItr = s.find("dream", pos);
	auto dreamerItr = s.find("dreamer", pos);
	auto eraseItr = s.find("erase", pos);
	auto eraserItr = s.find("eraser", pos);
	//cout << dreamItr << endl;
	//cout << dreamerItr << endl;
	//cout << eraseItr << endl;
	//cout << eraserItr << endl;
	bool ok = false;
	if (pos == dreamItr) {
		if (getPos(pos + 5)) return true;
	}
	if (pos == dreamerItr) {
		if (getPos(pos + 7)) return true;
	}
	if (pos == eraseItr) {
		if (getPos(pos + 5)) return true;
	}
	if (pos == eraserItr) {
		if (getPos(pos + 6)) return true;
	}
	if (!ok)	return false;
}
int main()
{
	cin >> s;
	auto dreamItr = s.find("dream");
	auto dreamerItr = s.find("dreamer");
	auto eraseItr = s.find("erase");
	auto eraserItr = s.find("eraser");
	Size = s.size();
	getPos(0);
	if (getPos(0))	cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
