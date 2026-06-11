#include<bits/stdc++.h>
using namespace std;
int main() {
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	string res = {};
	res.push_back(s1[0] + 'A' - 'a');
	res.push_back(s2[0] + 'A' - 'a');
	res.push_back(s3[0] + 'A' - 'a');
	cout << res << endl;
	return 0;
}
