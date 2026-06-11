#include <bits/stdc++.h>
using namespace std;

string s;

int main () {
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if (i%2 == 0){
			cout << s[i];
		}
	}
}