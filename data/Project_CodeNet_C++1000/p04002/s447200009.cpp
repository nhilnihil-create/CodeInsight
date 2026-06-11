#include <iostream>
#include <set>
#include <vector>
#define int long long
using namespace std;
typedef pair<int, int> P;

int h, w, n;
int a, b;
set<P> blackCells;
set<P> leftCorns;
int cntTable[10];

signed main() {
	int i;
	
	cin >> h >> w >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		a--; b--;
		blackCells.insert(P(a, b));
		for (int dy = -2; dy <= 0; dy++) {
			for (int dx = -2; dx <= 0; dx++) {
				int ny = a + dy;
				int nx = b + dx;
				if (0 <= ny && ny < h - 2 && 0 <= nx && nx < w - 2) {
					leftCorns.insert(P(ny, nx));
				}
			}
		}
	}
	
	for (set<P>::iterator it = leftCorns.begin(); it != leftCorns.end(); it++) {
		int ty = it->first;
		int tx = it->second;
		int cnt = 0;
		for (int dy = 0; dy < 3; dy++) {
			for (int dx = 0; dx < 3; dx++) {
				int y = ty + dy;
				int x = tx + dx;
				if (blackCells.find(P(y, x)) != blackCells.end()) {
					cnt++;
				}
			}
		}
		cntTable[cnt]++;
	}
	
	int ssum = 0;
	for (i = 1; i < 10; i++) ssum += cntTable[i];
	cntTable[0] = (h - 2) * (w - 2) - ssum;
	
	for (i = 0; i < 10; i++) {
		cout << cntTable[i] << endl;
	}
	return 0;
}