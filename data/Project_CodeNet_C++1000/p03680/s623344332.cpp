#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_trained(void) {
	int n;
	int a[100010];
	int cnt = 0;
	int next_button = 1;
	int now_button = 1;
	bool find = false;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		now_button = next_button;
		if (now_button == 2) {
			find = true;
			break;
		}
		next_button = a[now_button];
		cnt++;
	}

	if (!find) cnt = -1;
	cout << cnt << endl;
}

int main()
{
	b_trained();
    return 0;
}