#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int h, w; cin >> h >> w;
	int a;
	char c;
	const string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			string s; cin >> s;
			if (s == "snuke") {
				a = i + 1;
				c = str[j];
			}
		}
	}
	cout << c << a << '\n';
}