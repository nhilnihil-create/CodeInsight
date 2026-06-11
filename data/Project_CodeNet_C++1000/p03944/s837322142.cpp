#include<bits/stdc++.h>
using namespace std;


int main()
{
	int w, h, n; cin >> w >> h >> n;
	int W1 = 0, W2 = w, H1 = 0, H2 = h;
	for (int i = 0; i < n; ++i)
	{
		int x, y, a; cin >> x >> y >> a;
		if (a == 1) W1 = max(W1, x);
		else if (a == 2) W2 = min(W2, x);
		else if (a == 3) H1 = max(H1, y);
		else H2 = min(H2, y);
	}
	cout << max(W2-W1, 0) * max(H2-H1, 0) << endl;
}

