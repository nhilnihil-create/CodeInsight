#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e05 + 10;

int N;
int a[MAXN];

bool comp (const int& a, const int& b) {
	return a > b;
}

int getnum () {
	int num = 0;
	char ch = getchar ();

	while (! isdigit (ch))
		ch = getchar ();
	while (isdigit (ch))
		num = (num << 3) + (num << 1) + ch - '0', ch = getchar ();

	return num;
}

int main () {
	N = getnum ();
	for (int i = 1; i <= N; i ++)
		a[i] = getnum ();
	sort (a + 1, a + N + 1, comp);
	for (int i = 1; i <= N; i ++)
		if (a[i + 1] <= i) {
			bool win = false;
			if ((a[i] - i) & 1)
				win = true;
			if (! win && a[i + 1] == i) {
				int cnt = 1;
				for (int j = i + 1; j <= N; j ++) {
					if (a[j] < i) break;
					cnt ++;
				}
				if (! (cnt & 1))
					win = true;
			}
			win ? puts ("First") : puts ("Second");
			return 0;
		}

	return 0;
}

/*
2
1 3
*/

/*
3
1 2 1
*/

/*
3
1 2 3
*/