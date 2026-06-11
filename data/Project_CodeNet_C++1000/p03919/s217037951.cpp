#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int h, w,number;
	string s;
	char ans;
	
	cin >> h >> w;
	for (int j = 0; j < h; j++) {
		for (char a = 'A'; a < 65 + w; a++) {
			cin >> s;
			if (s == "snuke") {
				ans = a;
				number = j+1;
			}
		}
	}
	cout << ans << number << endl;
	return 0;
}