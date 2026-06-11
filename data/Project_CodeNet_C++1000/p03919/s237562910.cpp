#include<bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	cin >> h >> w;
	for (int i = 0;i < h*w;++i) {
		string s;
		cin >> s;
		if (s == "snuke") {
			char a = 'A';
			a += i%w;
			cout << a << i/w+1 << "\n";
			break;
		}
	}
	return 0;
}