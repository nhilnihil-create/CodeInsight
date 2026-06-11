#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void a_candy_easy(void) {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += i;
	cout << sum << endl;
}

int main()
{
	a_candy_easy();
    return 0;
}