#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_one_card_poker(void) {
	int a, b;
	cin >> a >> b;

	if (a == b) cout << "Draw" << endl;
	else if (a == 1) cout << "Alice" << endl;
	else if (b == 1) cout << "Bob" << endl;
	else cout << (a > b ? "Alice" : "Bob") << endl;
}

int main()
{
    a_one_card_poker();
    return 0;
}