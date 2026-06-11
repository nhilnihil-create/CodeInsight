#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

#include <climits>

using namespace std;


int main(){
	string s;
	cin >> s;

	vector<int> arr(26);

	for (int i = 0; i < s.size(); i++) {
		int num = s[i] - 'a';
		arr[num]++;
	}

	int ans = -1;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) {
			ans = i;
			break;
		}
	}

	if (ans == -1)cout << "None" << endl;
	else {
		int num2 = ans + 'a';
		char numnum = num2;
		cout << numnum << endl;
	}

	return 0;
}