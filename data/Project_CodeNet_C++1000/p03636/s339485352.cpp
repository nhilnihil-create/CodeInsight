#include <iostream>
#include <string.h>
#include <string>
using namespace std;


void b_i18n(void) {
	string s;
	cin >> s;
	int word_len = s.size()-2;
	string s_out = s[0] + to_string(word_len) + s[s.size() - 1];
	cout << s_out << endl;

}

int main()
{
	b_i18n();
    return 0;
}