#include <iostream>
#include <string>
using namespace std;

int main() {
	int ch[26];
	for(int i = 0; i < 26; i++) 
		ch[i] = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		ch[s[i] - 'a']++;
	}
	bool fool = true;
	for(int i = 0; i < s.size(); i++){
		if(ch[s[i] - 'a'] % 2 != 0) {
			fool = false;
			break;
		}
	}
	if(fool)
		printf("Yes\n");
	else printf("No\n");

}