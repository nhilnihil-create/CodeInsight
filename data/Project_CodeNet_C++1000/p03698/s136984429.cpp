#include <bits/stdc++.h>
using namespace std;

string s;
int cnt = 0;

int main () {
	cin >> s;
	for (char c = 'a'; c <= 'z'; c++){
		if (s.find(c) == -1){
			cnt++;
		}
	}
	if (cnt == 26 - s.length()){
		cout << "yes";
	} else {
		cout << "no";
	}
}