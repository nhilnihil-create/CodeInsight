#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	if(s[0] == s.back()){
		if(s.size()&1) cout << "Second" << endl;
		else cout << "First" << endl;
	} else {
		if(s.size()%2 == 0) cout << "Second" << endl;
		else cout << "First" << endl;
	}
	return 0;
}
