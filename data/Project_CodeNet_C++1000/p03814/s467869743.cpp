#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	string s;
	cin >> s;

	int maxLength;

	for (int i = 0; i <= s.size(); i++) {
		string tmpStr = "";
		if (s[i] == 'A') {
			for (int j = 0; j < s.size() - i; j++) {
				if (s[i + j] == 'Z') {
					tmpStr += s[i + j];
					maxLength = tmpStr.size();
					continue;
				}
				tmpStr += s[i + j];
			}
			break;
		}
	}

	cout << maxLength << endl;

	return 0;
}