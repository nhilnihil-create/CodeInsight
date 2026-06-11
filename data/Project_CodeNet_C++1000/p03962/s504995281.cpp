#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_atcoder_penki(void) {
	int a[3];
	for (int i = 0; i < 3; i++) cin >> a[i];
	int cnt = 3;
	sort(a, a + 3);

	for (int i = 0; i < 2; i++) {
		if (a[i] == a[i + 1]) cnt--;
	}

	cout << cnt << endl;

}

int main()
{
    a_atcoder_penki();
    return 0;
}