
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
	int len = s.length();

	int cnt_g = 0;
	int cnt_p = 0;
	int score = 0;
	for (int i = 0; i < len; i++) {
		if (cnt_g > cnt_p && s[i] == 'g') {
			cnt_p++;
			score++;

		}
		else if (s[i] == 'g') {
			cnt_g++;
		}
		else if (s[i] == 'p' && cnt_g == cnt_p){
			cnt_g++;
			score--;
		}
		else {
			cnt_p++;
		}

	}
	cout << score << endl;
}
