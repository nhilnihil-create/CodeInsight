#include<bits/stdc++.h>
using namespace std;
bool check(string sub, int n) {
	for (int i=0; i<(int)n/2; i++) {
		if (sub[i] != sub[n/2+i]) return false;
	}
	return true;
}
int main () {
	string s;
	cin >> s;
	int l = s.size()-1;
	if (l%2!=0) l--;
	while (l>0) {
		string sub=s.substr(0, l);
		if (check(sub, l) == true) {
			cout << l; 	
			return 0;
		}
		l-=2;
	}
	cout << 0;
	return 0;
}