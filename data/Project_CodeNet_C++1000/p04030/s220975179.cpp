#include<iostream>
#include<string>
using namespace std;
int main() {
	int g = 0;
	string s, r;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0' || s[i] == '1') {
				r += (s[i]);
				g++;
			}
			else if (s[i] == 'B') {
				if (!r.empty()) {
					r.erase(g - 1, 1);
					g--;
				}
			}

				
		}
		if (!r.empty())
		cout << r << endl;

	return 0;
}