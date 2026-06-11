#include <iostream>
using namespace std;

int main() {
	int H;
	cin >> H ;
	int i=1;
	for (;;i++) {
		if ((i *(i + 1) / 2) >= H && (i*(i - 1) / 2) <= H)
			break;
	}
	printf("%d\n", i);
	
	return 0;
}

