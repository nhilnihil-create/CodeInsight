#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_tatenaga(void) {
	int h, w;
	char c[110][110];
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> c[i][j];
		}
	}
	int h_pos = 0;
	int w_pos = 0;

	for (int i = 1; i <= h * 2; i++) {
		for (int j = 1; j <= w; j++) {
			h_pos = (i + 1) >> 1;
			w_pos = j;
			cout<<c[h_pos][w_pos];
		}
		cout << endl;
	}



}

int main()
{
	b_tatenaga();
    return 0;
}