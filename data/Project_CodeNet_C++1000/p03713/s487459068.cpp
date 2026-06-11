#include <iostream>
using namespace std;

int main(void)
{
    long long h, w, ans, i;

    cin >> h >> w;

    if (h * w % 3 == 0)
		ans = 0;
	else
		ans = min(h, w);

    for (i = 1; i <= h; i++)
	{
        long long A = i * w,
			B = (w / 2 + w % 2) * (h - i),
			C = w / 2 * (h - i);

		ans = min(ans, max(A, max(B, C)) - min(A, min(B, C)));
	}

	for (i = 1; i <= w; i++)
	{
        long long A = i * h,
			B = (h / 2 + h % 2) * (w - i),
			C = h / 2 * (w - i);

		ans = min(ans, max(A, max(B, C)) - min(A, min(B, C)));
	}

	cout << ans;
	return 0;
}