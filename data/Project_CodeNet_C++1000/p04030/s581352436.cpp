#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>


using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	vector<char> buff;
	string s;
	cin >> s;
	for (const char c : s) {
		if (c == 'B') {
			if (!buff.empty())buff.pop_back();
		}
		else buff.push_back(c);
	}
	for (const char c : buff)cout << c;
	cout << endl;
}