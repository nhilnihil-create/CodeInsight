#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string S;
	cin >> S;

	vector<char> ans;

	for (int i = 0; i <= 25; i++) {
		if (S.find(char(97 + i)) == string::npos) {
			ans.push_back(char(97 + i));
		}
	}

	bool b = ans.empty();

	if (b) {
		cout << "None" << endl;
	}
	else cout << ans[0] << endl;
}