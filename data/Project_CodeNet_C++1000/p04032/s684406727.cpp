
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;

int main() {
	string s;
	cin >> s;
	int a = -1, b = -1;

	for (int i = 1; i <= 2;i++) {
		for (int j = 0; i + j < s.length();j++) {
			if (s[j] == s[i + j]) {
				a = j + 1;
				b = i + j + 1;
				
			}
		}
	}

	cout << a << " " << b << endl;
}