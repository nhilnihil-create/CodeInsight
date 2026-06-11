#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_checkpoints(void) {
	int n, m;
	int a[60], b[60];
	int c[60], d[60];
	int num = 1;
	long int min_distance = 200000000;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i] >> d[i];
	}

	for (int i = 1; i <= n; i++) {
		min_distance = 200000000;
		num = 1;
		for (int j = 1; j <= m; j++) {
			int distance = abs(a[i] - c[j]) + abs(b[i] - d[j]);
			//cout << min_distance<<" "<<distance << endl;
			if (distance < min_distance) {
				min_distance = distance;
				num = j;
			}
		}
		cout << num << endl;
	}

}

int main()
{
	b_checkpoints();
    return 0;
}