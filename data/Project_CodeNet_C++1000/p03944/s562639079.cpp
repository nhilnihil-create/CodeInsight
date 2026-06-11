#include<bits/stdc++.h>
using namespace std;

int main() {
	int w, h, n; cin >> w >> h >> n;
	int xmin = 0, xmax = w, ymin = 0, ymax = h;
	for (int i = 0; i < n; i++)
	{
		int x, y, a;
		cin >> x >> y >> a;
		if(a == 1) xmin = max(xmin, x);
		else if(a == 2) xmax = min(xmax, x);
		else if(a == 3) ymin = max(ymin, y);
		else if(a == 4) ymax = min(ymax, y);
	}
	if(xmin >= xmax || ymin >= ymax) cout << "0" << endl;
	else cout << (xmax - xmin) * (ymax - ymin) << endl;

	return 0;
}
