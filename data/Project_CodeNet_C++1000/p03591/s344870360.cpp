#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	if(s.size()<4){
		cout << "No"; return 0;
	}else if(s[0]=='Y' && s[1]=='A' && s[2]=='K' && s[3]=='I'){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}