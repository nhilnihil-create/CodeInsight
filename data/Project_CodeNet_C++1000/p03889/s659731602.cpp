#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool mir(string s) {
	if (s.size() % 2 == 1)return false;
	for (int i = 0; i < s.size() / 2; i++){
		if (s[i] == 'b'&&s[s.size() - i - 1] == 'd');
		else if (s[i] == 'd'&&s[s.size() - i - 1] == 'b');
		else if (s[i] == 'p'&&s[s.size() - i - 1] == 'q');
		else if (s[i] == 'q'&&s[s.size() - i - 1] == 'p');
		else return false;
	}
	return true;
}
int main() {
	string s; cin >> s; if (mir(s))cout << "Yes\n"; else cout << "No\n";
}