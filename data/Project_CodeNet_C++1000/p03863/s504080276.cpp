#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool even = !(s.size() % 2);
	bool same = (s[0] == s[s.size() - 1]);
	if(even ^ same) cout << "Second";
	else cout << "First";
	return 0;
}


