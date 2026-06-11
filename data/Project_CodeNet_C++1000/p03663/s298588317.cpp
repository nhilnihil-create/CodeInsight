#include <bits/stdc++.h>
using namespace std;

// why am I so weak

void print(char ch, string s) {
	printf("%c %s\n", ch, s.c_str());
	fflush(stdout);
}
void print(char ch, long long x) {
	printf("%c %lld\n", ch, x);
	fflush(stdout);
}
int main() {
	print('?', "100000000000");

	{
		char wtf;
		scanf("\n%c", &wtf);

		if (wtf == 'Y') {
			long long res = 2;

			while (true) {
				print('?', 1ll * res);

				char ch;
				scanf("\n%c", &ch);

				if (ch == 'Y') {
					print('!', 1ll * res / 2);
					return 0;
				}

				res *= 10;
			}
		}
	}

	long long s = 1;

	while (true) {
		print('?', s);

		char ch;
		scanf("\n%c", &ch);

		if (ch == 'N') break;

		s *= 10;
	}

	long long lb = s / 10, ub = s;

	while (ub - lb > 1) {
		long long mid = (ub + lb) >> 1;

		print('?', mid * 10);

		char ch;
		scanf("\n%c", &ch);

		if (ch == 'Y') {
			ub = mid;
		} else lb = mid;
	}

	print('!', ub);

	return 0;
}
