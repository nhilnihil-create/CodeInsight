#include <bits/stdc++.h>
using namespace std;

enum Color {
	GRAY, BROWN, GREEN, CYAN, BLUE, YELLOW, ORANGE, RED, FREE
};

Color getColor(int r) {
	if (r < 400)
		return GRAY;
	else if (r < 800)
		return BROWN;
	else if (r < 1200)
		return GREEN;
	else if (r < 1600)
		return CYAN;
	else if (r < 2000)
		return BLUE;
	else if (r < 2400)
		return YELLOW;
	else if (r < 2800)
		return ORANGE;
	else if (r < 3200)
		return RED;
	else
		return FREE;
}

int main() {
	int N;
	cin >> N;
	map<Color, int> C;
	C[FREE] = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		C[getColor(a)]++;
	}
	int c = C.size() - 1;
	cout << max(c,1) << " " << c + C[FREE] << endl;
	return 0;
}
