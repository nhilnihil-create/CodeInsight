// ABC049B - たてなが

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int H, W;
	cin >> H >> W;
	string s[H];
	for (int i = 0; i < H; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < H; i++) {
		cout << s[i] << "\n" << s[i] << endl;
	}

	return 0;
}
