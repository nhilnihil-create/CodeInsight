#include <iostream>
#include <map>
using namespace std;

int main(){
#ifdef _DEBUG
	//freopen("_in" , "r", stdin );
	//freopen("_out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	s = "##" + s;
	for (int i = 2; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			cout << i - 2 << ' ' << i - 1 << '\n';
			return 0;
		}
		if (s[i] == s[i - 2]) {
			cout << i - 3 << ' ' << i - 1 << '\n';
			return 0;
		}
	}
	
	cout << "-1 -1\n";
}
