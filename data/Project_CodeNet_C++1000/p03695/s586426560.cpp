#include <bits/stdc++.h>
using namespace std;

struct Color{
	int gray = 0;
	int brown = 0;
	int green = 0;
	int lightBlue = 0;
	int blue = 0;
	int yellow = 0;
	int orange = 0;
	int red = 0;
	int any = 0;

	int sum() {
		return gray + brown + green + blue + \
			lightBlue + yellow + orange + red;
	}
};


void judge(int a, Color& color) {
	if (a <= 399) { color.gray = 1; }
	else if (a <= 799) { color.brown = 1; }
	else if (a <= 1199) { color.green = 1; }
	else if (a <= 1599) { color.blue = 1; }
	else if (a <= 1999) { color.lightBlue = 1; }
	else if (a <= 2399) { color.yellow = 1; }
	else if (a <= 2799) { color.orange = 1; }
	else if (a <= 3199) { color.red = 1; }
	else { color.any += 1; }

	return;
}

int main() {
	int n;
	Color color;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		judge(a, color);
	}
	int min_ans, max_ans;

	min_ans = color.sum();
	if (min_ans== 0 && color.any >0) { min_ans = 1; }
	max_ans = color.sum() + color.any;

	cout << min_ans << " " << max_ans << endl;
}