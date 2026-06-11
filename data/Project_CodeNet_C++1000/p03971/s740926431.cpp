#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int tuuka = 0;
	int oversea = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a' && tuuka < (a + b)) {
			cout << "Yes" << endl;
			tuuka++;
		}
		else if (s[i] == 'b' && tuuka < (a + b) && oversea < b) {
			cout << "Yes" << endl;
			tuuka++;
			oversea++;
		}
		else {
			cout << "No" << endl;
		}
	}

}
