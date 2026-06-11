#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <vector>

using namespace std;

int main()
{
    
	int n;
	cin >> n;

	vector<int> a(n);
	int oddNum = 0, evenNum = 0;


	for (auto& i : a) {
		cin >> i;
		if (i % 2 == 0)evenNum++;
		else oddNum++;
	}
	
	evenNum += oddNum / 2;
	oddNum %= 2;
	evenNum = min(evenNum, 1);

	if (oddNum + evenNum == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}





	return 0;

}


