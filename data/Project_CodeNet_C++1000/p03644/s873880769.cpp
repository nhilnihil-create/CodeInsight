#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void b_break_number(void) {
	int n,m;
	cin >> n;
	int cnt = 0;
	int cnt_max = 0;
	int n_max=1;
	for (int i = 1; i <= n; i++) {
		m = i;
		cnt = 0;
		while (true) {
			if ((m & 0x1) == 0x1) break;
			m = m >> 1;
			cnt++;
		}
		if (cnt > cnt_max) {
			cnt_max = cnt;
			n_max = i;
		}
	}
	cout << n_max << endl;
}

int main()
{
	b_break_number();
    return 0;
}