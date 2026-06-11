#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_counting_roads(void) {
	int n, m;
	int a[100];
	int b[100];
	int cnt[100] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i];

	for (int i = 0; i < m; i++) {
		cnt[a[i]]++;
		cnt[b[i]]++;
	}

	for (int i = 1; i <= n; i++) cout << cnt[i] << endl;
}

int main()
{
	b_counting_roads();
    return 0;
}