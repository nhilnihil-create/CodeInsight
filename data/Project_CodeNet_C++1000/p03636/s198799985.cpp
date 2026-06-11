#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	
	cin >> s;
	string ans;

	ans = s[0];

	int size = s.size() - 2;
	ans += to_string(size);


	ans += s[s.size()-1];

	cout << ans << endl;

	return 0;
}