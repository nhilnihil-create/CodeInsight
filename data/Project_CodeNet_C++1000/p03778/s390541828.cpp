#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_narrow_rectangle_easy(void) {
	int w, a, b;
	cin >> w >> a >> b;
	int a_end = a + w;
	int b_end = b + w;

	if (b >= a_end) cout << b - a_end << endl;
	else if (b_end <= a) cout << a - b_end << endl;
	else cout << 0 << endl;
}

int main()
{
	b_narrow_rectangle_easy();
    return 0;
}