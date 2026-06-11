#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, cnt = 0, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (a == i) {
			cnt++;
		}
		else {
			ans += (cnt + 1) / 2;
			cnt = 0;
		}
	}
	cout << (ans += (cnt + 1) / 2) << '\n';
	return 0;
}