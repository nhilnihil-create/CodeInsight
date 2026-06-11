#include <iostream>
using namespace std;

int main(){
	string s; cin >> s;
	while (s.size() >= 5) {
		string fi, si, sv;
		if (s.size() >= 5) fi = s.substr(0, 5);
		if (s.size() >= 6) si = s.substr(0, 6);
		if (s.size() >= 7) sv = s.substr(0, 7);
		if (sv == "dreamer" && s[7] != 'a') s.erase(0, 7); else
		if (si == "eraser"  && s[6] != 'a') s.erase(0, 6); else
		if (fi == "erase" || fi == "dream") s.erase(0, 5);
		else break;
	}
	cout << (s.size() ? "NO" : "YES") << '\n';
}
