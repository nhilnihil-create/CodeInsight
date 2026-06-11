#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_picture_frame(void) {
	int h, w;
	char a[110][110];
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < (h + 2); i++) {
		for (int j = 0; j < (w + 2); j++) {
			if ((i == 0) || (i == h + 1)) cout << "#";
			else if ((j == 0) || (j == w + 1)) cout << "#";
			else cout << a[i - 1][j - 1];
		}
		cout << endl;
	}
}


int main()
{
	b_picture_frame();
    return 0;
}
