#include <iostream>
using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	string ans = "";
	ans.push_back(s1[0] - 'a' + 'A');
	ans.push_back(s2[0] - 'a' + 'A');
	ans.push_back(s3[0] - 'a' + 'A');
	cout << ans << endl;
}