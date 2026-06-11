#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 100000000

int main() {
	string s;
	cin >> s;

	int point = 0;
	int ans1 = -1, ans2 = -1;

	for (int i = 0; i < s.size()-2; i++) {
		if (s[point] == s[point + 1]) {
			ans1 = point+1;
			ans2 = point+2;
			break;
		} else if(s[point] == s[point + 2]){
			ans1 = point + 1;
			ans2 = point + 3;
			break;
		}
		point++;
	}

	if (s[0] == s[1]) {
		ans1 = 1;
		ans2 = 2;
	} else if (s[s.size() - 2] == s[s.size() - 1]) {
		ans1 = s.size() - 1;
		ans2 = s.size();
	}

	cout << ans1 << " " << ans2 << endl;
}