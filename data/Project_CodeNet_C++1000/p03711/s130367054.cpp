#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	char G[12] = { 'A','C','A','B','A','B','A','A','B','A','B','A' };
	int x, y;
	cin >> x >> y;

	if (G[x - 1] == G[y - 1]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
