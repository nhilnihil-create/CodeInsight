#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void c_colorful_leaderboard(void) {
	int n;
	int rate[9] = { 0 };
	int rate_val = 0;

	int color_min = 0;
	int color_max = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rate_val;
		if (rate_val > 3199) rate[8]++;
		else if (rate_val > 2799) rate[7]++;
		else if (rate_val > 2399) rate[6]++;
		else if (rate_val > 1999) rate[5]++;
		else if (rate_val > 1599) rate[4]++;
		else if (rate_val > 1199) rate[3]++;
		else if (rate_val > 799)  rate[2]++; // green
		else if (rate_val > 399)  rate[1]++;
		else                      rate[0]++;
	}

	for (int i = 0; i < 8; i++) {
		if (rate[i] > 0) color_min++;
	}

	color_max = color_min;

	if (color_min == 0 && rate[8] > 0) color_min++;

	color_max += rate[8];

	cout << color_min << " " << color_max << endl;
}

int main()
{
    c_colorful_leaderboard();

    return 0;
}