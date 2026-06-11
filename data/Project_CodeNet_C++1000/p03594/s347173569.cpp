#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int H, W, d;

char c(int x, int y) {
	x = (x % (d * 2) + d * 2) % (d * 2);
	y = (y % (d * 2) + d * 2) % (d * 2);
	if (x < d) {
		if (y < d)return 'R';
		else return 'Y';
	}
	else {
		if (y < d)return 'B';
		else return 'G';
	}
}

int main() {
	cin >> H >> W >> d;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << c(i + j, i - j);
		}
		cout << endl;
	}
}