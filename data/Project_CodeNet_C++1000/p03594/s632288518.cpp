#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 2000010;
const int oo = 1e9;

int h , w, d;
char color[4] = {'R', 'G', 'Y', 'B'};
char ans[510][510];
int OFFSET = 1100;

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> h >> w >> d;
	int offset = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0 ; j < w ; ++j) {
			int newI = i-j+OFFSET;
			int newJ = i+j+OFFSET;
			int c = (newI/d)%2 + 2*((newJ/d)%2);
			ans[i][j] = color[c];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0 ; j < w ; ++j) {
			printf("%c", ans[i][j]);
		}
		puts("");
	}
	return 0;
}